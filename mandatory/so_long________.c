/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long________.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:27:12 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 15:34:03 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>

#include "so_long.h"
#include "mlx.h"

int	map_in_range(t_map *map, size_t x, size_t y)
{
	return (0 <= x && x < map->height && 0 <= y && y < map->width);
}

void	free_map(t_map *map)
{
	size_t	index;

	index = -1;
	while (++index < map->height)
		free(map->map[index]);
	free(map->map);
	free(map);
}

void	game_end(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->player_foreward);
	mlx_destroy_image(game->mlx, game->player_backward);
	mlx_destroy_image(game->mlx, game->door_close);
	mlx_destroy_image(game->mlx, game->door_open);
	mlx_destroy_image(game->mlx, game->grass);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->key);
	mlx_destroy_window(game->mlx, game->window);
	free(game);
	exit(0);
}
