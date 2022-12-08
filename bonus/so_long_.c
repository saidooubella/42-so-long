/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:22:31 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 12:29:12 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "so_long.h"
#include "utils.h"

void	parsing_part_six(t_parsing_state *state)
{
	if (state->keys_count == 0)
		error("This map requires at least one collectable");
	if (!state->prev_is_wall)
		error("The last line isn't a wall");
	if (!state->has_exit && !state->has_player)
		error("This map requires a player and an exit");
	if (!state->has_exit)
		error("This map requires an exit");
	if (!state->has_player)
		error("This map requires a player");
}

void	init_fire_state(t_fire_state *fire_state, size_t index, int col)
{
	if (index % 2 == 0)
		fire_state->orientation = VERTICAL;
	else
		fire_state->orientation = HORIZONTAL;
	fire_state->backward = 1;
	fire_state->x = index;
	fire_state->y = col;
}

void	proccess_line(t_parsing_state *state, t_map *map)
{
	size_t	col;

	col = -1;
	state->line = get_next_line(&state->file_state, state->fd);
	if (state->line == 0)
		error("Something went wrong");
	while (state->line[++col])
	{
		if (state->line[col] == 'F')
			init_fire_state(&map->fire_states[state->state_index++],
				state->index, col);
		if (state->line[col] == 'F')
			state->line[col] = '0';
	}
	map->map[state->index++] = state->line;
}

void	map_parsing(t_parsing_state *state, int argc, char *filename)
{
	init_parsing_state(state, argc, filename);
	while (state->line != 0)
	{
		parsing_part_one(state);
		parsing_part_two(state);
		parsing_part_three(state);
		parsing_part_four(state);
		parsing_part_five(state);
	}
	parsing_part_six(state);
	close(state->fd);
}

t_map	*map_validation_and_generation(t_parsing_state *state)
{
	t_map	*map;

	validate_and_open_file(state->filename, &state->file_state, &state->fd, 0);
	map = init_map(state);
	state->index = 0;
	state->state_index = 0;
	while (state->index < state->map_height)
		proccess_line(state, map);
	if (!validate_path(map, state->player_x, state->player_y))
		error("The player has no way out on this map");
	close(state->fd);
	return (map);
}
