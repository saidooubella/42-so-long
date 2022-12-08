/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_________.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:00:29 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 13:00:35 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "so_long.h"
#include "mlx.h"

void	update_fire_satate(t_fire_state *state, char cell)
{
	size_t	value;

	value = 1;
	if (state->backward)
		value = -1;
	if (cell != 'P' && cell != '0')
		state->backward = !state->backward;
	else if (state->orientation == VERTICAL)
		state->x += value;
	else
		state->y += value;
}

void	*current_sprite_frame(t_game *game, t_sprite *sprite)
{
	if (game->forward)
		return (sprite->normal[game->index]);
	return (sprite->reverse[game->index]);
}

void	render_cell(t_game *game, char cell, size_t x, size_t y)
{
	if (cell == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, x, y);
	else if (cell == 'E')
		mlx_put_image_to_window(
			game->mlx, game->window,
			game->door->frames[game->door->index], x, y);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->grass, x, y);
	if (cell == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->key, x, y);
}

void	render_player(t_game *game, t_sprite *sprite)
{
	mlx_put_image_to_window(
		game->mlx,
		game->window,
		current_sprite_frame(game, sprite),
		game->map->player_y * game->taile_height + 8,
		game->map->player_x * game->taile_width);
}
