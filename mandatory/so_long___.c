/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long___.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:18:29 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 15:45:43 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

#include "string_utils.h"
#include "ft_printf.h"
#include "so_long.h"

void	update_player_coordinates(t_game *game, size_t x, size_t y)
{
	game->map->player_x = x;
	game->map->player_y = y;
	ft_printf(STDOUT_FILENO, "%z\n", ++game->moves_count);
}

void	update_game_state(t_game *game, size_t x, size_t y, int forward)
{
	if (game->forward != forward)
	{
		game->forward = forward;
		return ;
	}
	if (map_in_range(game->map, x, y))
	{
		if (game->map->map[x][y] == 'E')
		{
			if (game->map->keys_count == game->collected_keys)
				game_end(game);
		}
		else if (game->map->map[x][y] != '1')
			update_player_coordinates(game, x, y);
		if (game->map->map[x][y] == 'C')
		{
			game->collected_keys += 1;
			game->map->map[x][y] = '0';
		}
	}
}

int	key_down_handler(int key_code, t_game *game)
{
	if (key_code == 53)
		game_end(game);
	else if (key_code == 2)
		update_game_state(game, game->map->player_x,
			game->map->player_y + 1, 1);
	else if (key_code == 0)
		update_game_state(game, game->map->player_x,
			game->map->player_y - 1, 0);
	else if (key_code == 13)
		update_game_state(game, game->map->player_x - 1,
			game->map->player_y, game->forward);
	else if (key_code == 1)
		update_game_state(game, game->map->player_x + 1,
			game->map->player_y, game->forward);
	return (0);
}

int	exit_handler(t_game *game)
{
	game_end(game);
	return (0);
}
