/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_____.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:59:49 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 12:32:46 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "string_utils.h"
#include "ft_printf.h"
#include "so_long.h"
#include "utils.h"
#include "mlx.h"

t_sprite	*current_sprite(t_game *game)
{
	if (game->player_state == RUNNING)
		return (game->run);
	if (game->player_state == DEAD)
		return (game->dead);
	if (game->player_state == IDLE)
		return (game->idle);
	error("Illegal state error");
	return (0);
}

void	write_moves_on_screen(t_game *game)
{
	char	*number;
	char	*joined;

	number = int_to_string(game->moves_count, BASE_10, 10);
	if (number == 0)
		error("Out of memory");
	joined = string_join(number, " Moves");
	free(number);
	mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFFFF, joined);
	free(joined);
}

void	update_elements_frames(t_game *game, t_sprite *sprite)
{
	if (game->loop_index++ > 3)
	{
		if (game->collected_keys == game->map->keys_count
			&& game->door->index < game->door->count - 1)
			game->door->index += 1;
		game->index = (game->index + 1) % sprite->count;
		game->fire->index = (game->fire->index + 1) % game->fire->count;
		game->loop_index = 0;
	}
}

int	in_fire_spot(t_map *map)
{
	size_t	player_x;
	size_t	player_y;
	size_t	index;

	player_x = map->player_x;
	player_y = map->player_y;
	index = -1;
	while (++index < map->fire_count)
		if (map->fire_states[index].x == player_x
			&& map->fire_states[index].y == player_y)
			return (1);
	return (0);
}

char	get_new_fire_cell(t_fire_state *state, t_map *map)
{
	size_t	cell_x;
	size_t	cell_y;
	size_t	value;

	value = 1;
	if (state->backward)
		value = -1;
	cell_x = state->x;
	cell_y = state->y;
	if (state->orientation == VERTICAL)
		cell_x += value;
	else
		cell_y += value;
	return (map->map[cell_x][cell_y]);
}
