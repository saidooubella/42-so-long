/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long____.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:16:45 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 14:58:30 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "so_long.h"
#include "mlx.h"

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

int	game_loop_handler(t_game *game)
{
	size_t			i;
	int				x;

	i = 0;
	x = 0;
	while (i < game->map->width)
	{
		render_cells(game, i, x);
		x += game->taile_height;
		i += 1;
	}
	render_player(game);
	return (0);
}
