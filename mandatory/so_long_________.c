/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_________.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:00:29 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 15:12:29 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "so_long.h"
#include "mlx.h"

void	render_cell(t_game *game, char cell, size_t x, size_t y)
{
	if (cell == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, x, y);
	else if (cell == 'E')
	{
		if (game->collected_keys == game->map->keys_count)
			mlx_put_image_to_window(game->mlx, game->window,
				game->door_open, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->window,
				game->door_close, x, y);
	}
	else
		mlx_put_image_to_window(game->mlx, game->window, game->grass, x, y);
	if (cell == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->key, x, y);
}

void	render_player(t_game *game)
{
	void	*sprite;

	sprite = game->player_backward;
	if (game->forward)
		sprite = game->player_foreward;
	mlx_put_image_to_window(
		game->mlx, game->window, sprite,
		game->map->player_y * game->taile_height + 8,
		game->map->player_x * game->taile_width);
}
