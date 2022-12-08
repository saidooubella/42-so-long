/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:47:40 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 11:05:45 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "get_next_line.h"

static t_read_info	line_info(char *string, size_t offset, size_t size)
{
	t_read_info	info;
	size_t		index;

	info.has_newline = 0;
	info.line_size = 0;
	index = offset;
	while (index < size)
	{
		if (string[index] == '\n')
		{
			info.has_newline = 1;
			return (info);
		}
		info.line_size += 1;
		index += 1;
	}
	return (info);
}

static int	read_to_buffer(int fd, t_state_holder *state)
{
	if (state->offset >= (size_t) state->read_size)
	{
		state->read_size = read(fd, state->buffer, BUFFER_SIZE);
		state->offset = 0;
		if (state->read_size < 1)
		{
			if (state->read_size == 0)
				return (1);
			state->read_size = 0;
			return (0);
		}
	}
	return (-1);
}

static int	read_line(int fd, t_string_builder *builder
	, t_state_holder *state, int *has_nl)
{
	t_read_info	info;
	int			res;

	while (1)
	{
		res = read_to_buffer(fd, state);
		if (res != -1)
			return (res);
		info = line_info(state->buffer, state->offset, state->read_size);
		if (!string_builder_append(builder, state->buffer + state->offset
				, info.line_size))
			return (0);
		state->offset += info.line_size;
		if (info.has_newline)
		{
			*has_nl = 1;
			state->offset += 1;
			return (1);
		}
	}
}

char	*get_next_line(t_state_holder *state, int fd)
{
	t_string_builder	*builder;
	char				*result;
	int					has_nl;

	if (fd < 0)
		return (0);
	builder = string_builder_new();
	has_nl = 0;
	if (builder == 0)
		return (0);
	result = 0;
	if (read_line(fd, builder, state, &has_nl) && (builder->size > 0 || has_nl))
		result = string_builder_to_cstr(builder);
	string_builder_free(&builder);
	return (result);
}
