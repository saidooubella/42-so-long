/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init____.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:48:00 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 17:22:06 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long_init.h"
#include "so_long.h"
#include "utils.h"
#include "mlx.h"

static void	init_game_part_one(
	t_game *game, t_map *map, int *width, int *height)
{
	game->mlx = mlx_init();
	if (game->mlx == 0)
		error("Failed to setup the window");
	game->player_state = IDLE;
	game->collected_keys = 0;
	game->moves_count = 0;
	game->fire_index = 0;
	game->forward = 1;
	game->index = 0;
	game->map = map;
	game->door = init_door_animatable(game->mlx, width, height);
	game->fire = init_fire_animatable(game->mlx, width, height);
	game->idle = init_idle_sprite(game->mlx, width, height);
	game->dead = init_dead_sprite(game->mlx, width, height);
	game->run = init_run_sprite(game->mlx, width, height);
}

static void	init_game_part_two(t_game *game, t_map *map, char *name)
{
	int	t_w;
	int	t_h;

	game->grass = load_xpm_file(game->mlx, "img/grass.xpm", &t_w, &t_h);
	game->wall = load_xpm_file(game->mlx, "img/tile.xpm", &t_w, &t_h);
	game->key = load_xpm_file(game->mlx, "img/key.xpm", &t_w, &t_h);
	game->taile_width = t_w;
	game->taile_height = t_h;
	game->window_width = map->width * t_w;
	game->window_height = map->height * t_h;
	game->window = mlx_new_window(
			game->mlx, game->window_width, game->window_height, name);
	if (game->window == 0)
		error("Can't create a window");
}

t_game	*init_game(t_map *map, char *name)
{
	t_game	*game;
	int		height;
	int		width;

	game = malloc(sizeof(t_game));
	if (game == 0)
		error("Out of memory");
	init_game_part_one(game, map, &width, &height);
	init_game_part_two(game, map, name);
	mlx_loop_hook(game->mlx, game_loop_handler, game);
	mlx_hook(game->window, 2, 1, key_down_handler, game);
	mlx_hook(game->window, 3, 2, key_up_handler, game);
	mlx_hook(game->window, 17, 1, exit_handler, game);
	mlx_loop(game->mlx);
	return (game);
}
