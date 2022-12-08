/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:51:26 by soubella          #+#    #+#             */
/*   Updated: 2022/10/25 19:38:18 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>

# define DEFAULT_CAPACITY 16
# define BUFFER_SIZE 8192

typedef struct s_state_holder
{
	char	buffer[BUFFER_SIZE];
	ssize_t	read_size;
	size_t	offset;
}	t_state_holder;

typedef struct s_string_builder
{
	char	*buffer;
	size_t	capacity;
	size_t	size;
}	t_string_builder;

typedef struct s_read_info
{
	int		has_newline;
	size_t	line_size;
}	t_read_info;

int					string_builder_append(t_string_builder *b,
						char *str, size_t size);
char				*string_builder_to_cstr(t_string_builder *builder);
void				string_builder_free(t_string_builder **b);
t_string_builder	*string_builder_new(void);
char				*get_next_line(t_state_holder *state, int fd);

#endif
