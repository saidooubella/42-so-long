/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:51:37 by soubella          #+#    #+#             */
/*   Updated: 2022/10/11 16:44:52 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "get_next_line.h"

t_string_builder	*string_builder_new(void)
{
	t_string_builder	*builder;

	builder = malloc(sizeof(t_string_builder));
	if (builder == 0)
		return (0);
	builder->buffer = malloc(DEFAULT_CAPACITY);
	if (builder->buffer == 0)
	{
		free(builder);
		return (0);
	}
	builder->capacity = DEFAULT_CAPACITY;
	builder->size = 0;
	return (builder);
}

void	string_builder_free(t_string_builder **b)
{
	free((*b)->buffer);
	free(*b);
	*b = 0;
}

static int	string_builder_ensure_capacity(t_string_builder *b, size_t size)
{
	char	*new_buffer;
	size_t	new_capacity;
	size_t	index;

	if (b->capacity > b->size + size)
		return (1);
	new_capacity = (b->capacity << 1) + size;
	new_buffer = malloc(new_capacity);
	if (new_buffer == 0)
		return (0);
	index = -1;
	while (++index < b->size)
		new_buffer[index] = b->buffer[index];
	free(b->buffer);
	b->capacity = new_capacity;
	b->buffer = new_buffer;
	return (1);
}

int	string_builder_append(t_string_builder *b, char *str, size_t size)
{
	size_t	index;

	if (!string_builder_ensure_capacity(b, size))
		return (0);
	index = 0;
	while (index < size)
		b->buffer[b->size++] = str[index++];
	return (1);
}

char	*string_builder_to_cstr(t_string_builder *b)
{
	char	*string;
	size_t	index;

	string = malloc(b->size + 1);
	if (string == 0)
		return (0);
	index = -1;
	while (++index < b->size)
		string[index] = b->buffer[index];
	string[b->size] = 0;
	return (string);
}
