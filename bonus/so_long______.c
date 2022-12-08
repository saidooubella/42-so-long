/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long______.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:54:43 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 12:34:27 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#include "string_utils.h"
#include "so_long.h"
#include "utils.h"

static char	*read_first_line(char *filename, t_state_holder *file_state, int fd)
{
	char	*line;

	line = get_next_line(file_state, fd);
	if (line == 0)
		error("The file is empty: %s", filename);
	return (line);
}

char	*validate_and_open_file(
	char *filename, t_state_holder *file_state, int *fd, int readln)
{
	char	*line;

	line = 0;
	file_state->read_size = 0;
	file_state->offset = 0;
	if (!string_ends_not_only_with(filename, ".ber"))
		error("Wrong file extension: %s", filename);
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		error("%s: %s", strerror(errno), filename);
	if (readln == 1)
		line = read_first_line(filename, file_state, *fd);
	return (line);
}

void	validate_arguments(int argc)
{
	if (argc > 2)
		error("Too many arguments");
	if (argc < 2)
		error("Too few arguments");
}

void	init_map_content(t_parsing_state *state, t_map *map)
{
	map->map = malloc(sizeof(char *) * state->map_height);
	if (map->map == 0)
		error("Out of memory");
	map->fire_states = malloc(sizeof(t_fire_state) * state->fire_count);
	if (map->fire_states == 0)
		error("Out of memory");
}

t_map	*init_map(t_parsing_state *state)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == 0)
		error("Out of memory");
	map->height = state->map_height;
	map->width = state->map_width;
	map->player_x = state->player_x;
	map->player_y = state->player_y;
	map->keys_count = state->keys_count;
	map->fire_count = state->fire_count;
	init_map_content(state, map);
	return (map);
}
