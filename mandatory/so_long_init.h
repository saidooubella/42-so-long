/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:03:12 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 16:31:18 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_INIT_H
# define SO_LONG_INIT_H

# include "so_long.h"

void			init_game_part_one(
					t_game *game, t_map *map, int *width, int *height);
void			init_game_part_two(t_game *game, t_map *map, char *name);
t_game			*init_game(t_map *map, char *name);

#endif
