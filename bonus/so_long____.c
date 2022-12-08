/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long____.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:16:45 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 14:52:00 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "so_long.h"
#include "mlx.h"

void	update_fires_state(t_game *game)
{
	t_fire_state	*state;
	size_t			index;

	index = -1;
	if (game->player_state != DEAD && game->fire_index > FIRE_SLOW_DOWN)
	{
		while (++index < game->map->fire_count)
		{
			state = &game->map->fire_states[index];
			update_fire_satate(state, get_new_fire_cell(state, game->map));
		}
	}
}

void	render_fire(t_game *game)
{
	size_t			index;

	index = -1;
	while (++index < game->map->fire_count)
	{
		mlx_put_image_to_window(
			game->mlx,
			game->window,
			game->fire->frames[game->fire->index],
			game->map->fire_states[index].y * game->taile_height,
			game->map->fire_states[index].x * game->taile_height);
	}
}

void	render_cells(t_game *game, size_t i, size_t x)
{
	size_t			j;
	int				y;

	j = 0;
	y = 0;
	while (j < game->map->height)
	{
		render_cell(game, game->map->map[j][i], x, y);
		y += game->taile_width;
		j += 1;
	}
}

void	update_player_state(t_game *game, t_sprite *sprite)
{
	if (game->player_state != DEAD && in_fire_spot(game->map))
	{
		game->player_state = DEAD;
		game->index = 0;
	}
	if (game->fire_index++ > FIRE_SLOW_DOWN)
		game->fire_index = 0;
	if (game->player_state == DEAD && game->index == sprite->count - 1)
		game_end(game);
}

int	game_loop_handler(t_game *game)
{
	t_sprite		*sprite;
	size_t			i;
	int				x;

	i = 0;
	x = 0;
	sprite = current_sprite(game);
	while (i < game->map->width)
	{
		render_cells(game, i, x);
		x += game->taile_height;
		i += 1;
	}
	render_player(game, sprite);
	render_fire(game);
	update_fires_state(game);
	update_player_state(game, sprite);
	update_elements_frames(game, sprite);
	write_moves_on_screen(game);
	return (0);
}
