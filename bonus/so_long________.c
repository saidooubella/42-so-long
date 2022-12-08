/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long________.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:27:12 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 12:35:25 by soubella         ###   ########.fr       */
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
	free(map->fire_states);
	free(map);
}

void	free_sprite(t_sprite *sprite, void *mlx)
{
	size_t	index;

	index = -1;
	while (++index < sprite->count)
	{
		mlx_destroy_image(mlx, sprite->reverse[index]);
		mlx_destroy_image(mlx, sprite->normal[index]);
	}
	free(sprite->reverse);
	free(sprite->normal);
	free(sprite);
}

void	free_animatable(t_animatable *animatable, void *mlx)
{
	size_t	index;

	index = -1;
	while (++index < animatable->count)
		mlx_destroy_image(mlx, animatable->frames[index]);
	free(animatable->frames);
	free(animatable);
}

void	game_end(t_game *game)
{
	free_map(game->map);
	free_sprite(game->idle, game->mlx);
	free_sprite(game->dead, game->mlx);
	free_sprite(game->run, game->mlx);
	free_animatable(game->door, game->mlx);
	free_animatable(game->fire, game->mlx);
	mlx_destroy_image(game->mlx, game->grass);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->key);
	mlx_destroy_window(game->mlx, game->window);
	free(game);
	exit(0);
}
