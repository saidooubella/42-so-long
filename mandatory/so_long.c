/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:03:10 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 16:31:32 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>

#include "get_next_line.h"
#include "string_utils.h"
#include "so_long_init.h"
#include "ft_printf.h"
#include "so_long.h"
#include "utils.h"
#include "stack.h"

int	main(int argc, char **argv)
{
	t_parsing_state	state;
	t_game			*game;
	t_map			*map;

	map_parsing(&state, argc, argv[1]);
	map = map_validation_and_generation(&state);
	game = init_game(map, argv[0]);
	game_end(game);
	return (0);
}
