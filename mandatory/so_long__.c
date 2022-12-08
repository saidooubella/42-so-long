/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:20:21 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 14:53:12 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>

#include "string_utils.h"
#include "so_long.h"
#include "utils.h"

void	parsing_part_one(t_parsing_state *state)
{
	state->line_width = string_length(state->line);
	if (state->line_width == 0)
		error("Line %z is empty", state->line_number);
	if (state->line_width > state->map_width)
		error("Line %z is longer than the first line", state->line_number);
	if (state->line_width < state->map_width)
		error("Line %z is shorter than the first line", state->line_number);
	state->prev_is_wall = is_wall(state->line);
	if (!has_only(state->line, "01CEP"))
		error("Line %z contains an illegal character", state->line_number);
}

void	parsing_part_two(t_parsing_state *state)
{
	if (!state->prev_is_wall && state->line_number == 1)
		error("The first line isn't a wall");
	else
	{
		if (state->line[0] != '1' && state->line[state->line_width - 1] != '1')
			error("Line %z doesn't start and ends with a wall",
				state->line_number);
		if (state->line[0] != '1')
			error("Line %z doesn't start with a wall", state->line_number);
		if (state->line[state->line_width - 1] != '1')
			error("Line %z doesn't end with a wall", state->line_number);
	}
}

void	parsing_part_three(t_parsing_state *state)
{
	if (has_char(state->line, 'E'))
	{
		if (state->has_exit)
			error("This map has an additional exit at line %z",
				state->line_number);
		if (char_count(state->line, 'E') > 1)
			error("This map has multiple exits at line %z", state->line_number);
		state->has_exit = 1;
	}
}

void	parsing_part_four(t_parsing_state *state)
{
	if (has_char(state->line, 'P'))
	{
		if (state->has_player)
			error("This map has an additional player at line %z",
				state->line_number);
		if (char_count(state->line, 'P') > 1)
			error("This map has multiple players at line %z",
				state->line_number);
		state->player_x = state->line_number - 1;
		state->player_y = index_of(state->line, 'P');
		state->has_player = 1;
	}
}

void	parsing_part_five(t_parsing_state *state)
{
	state->keys_count += char_count(state->line, 'C');
	free(state->line);
	state->line = get_next_line(&state->file_state, state->fd);
	state->line_number++;
	state->map_height++;
}
