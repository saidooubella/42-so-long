/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:03:12 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 16:32:12 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_INIT_H
# define SO_LONG_INIT_H

# include "so_long.h"

t_animatable	*init_door_animatable(void *mlx, int *width, int *height);
t_animatable	*init_fire_animatable(void *mlx, int *width, int *height);
t_sprite		*init_idle_sprite(void *mlx, int *width, int *height);
t_sprite		*init_dead_sprite(void *mlx, int *width, int *height);
t_sprite		*init_run_sprite(void *mlx, int *width, int *height);
t_game			*init_game(t_map *map, char *name);

#endif
