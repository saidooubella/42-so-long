/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:39:19 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 11:16:08 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"
#include "utils.h"

static void	init_door_frames(
	t_animatable *door, void *mlx, int *w, int *h)
{
	door->frames = malloc(sizeof(void *) * 10);
	if (door->frames == 0)
		error("Out of memory");
	door->frames[0] = load_xpm_file(mlx, "img/door__000.xpm", w, h);
	door->frames[1] = load_xpm_file(mlx, "img/door__001.xpm", w, h);
	door->frames[2] = load_xpm_file(mlx, "img/door__002.xpm", w, h);
	door->frames[3] = load_xpm_file(mlx, "img/door__003.xpm", w, h);
	door->frames[4] = load_xpm_file(mlx, "img/door__004.xpm", w, h);
	door->frames[5] = load_xpm_file(mlx, "img/door__005.xpm", w, h);
	door->frames[6] = load_xpm_file(mlx, "img/door__006.xpm", w, h);
	door->frames[7] = load_xpm_file(mlx, "img/door__007.xpm", w, h);
	door->frames[8] = load_xpm_file(mlx, "img/door__008.xpm", w, h);
	door->frames[9] = load_xpm_file(mlx, "img/door__009.xpm", w, h);
	door->count = 10;
	door->index = 0;
}

t_animatable	*init_door_animatable(void *mlx, int *w, int *h)
{
	t_animatable	*door;

	door = malloc(sizeof(t_animatable));
	if (door == 0)
		error("Out of memory");
	init_door_frames(door, mlx, w, h);
	door->count = 10;
	door->index = 0;
	return (door);
}

static void	init_fire_frames(
	t_animatable *fire, void *mlx, int *w, int *h)
{
	fire->frames = malloc(sizeof(void *) * 8);
	if (fire->frames == 0)
		error("Out of memory");
	fire->frames[0] = load_xpm_file(mlx, "img/fire__000.xpm", w, h);
	fire->frames[1] = load_xpm_file(mlx, "img/fire__001.xpm", w, h);
	fire->frames[2] = load_xpm_file(mlx, "img/fire__002.xpm", w, h);
	fire->frames[3] = load_xpm_file(mlx, "img/fire__003.xpm", w, h);
	fire->frames[4] = load_xpm_file(mlx, "img/fire__004.xpm", w, h);
	fire->frames[5] = load_xpm_file(mlx, "img/fire__005.xpm", w, h);
	fire->frames[6] = load_xpm_file(mlx, "img/fire__006.xpm", w, h);
	fire->frames[7] = load_xpm_file(mlx, "img/fire__007.xpm", w, h);
	fire->count = 8;
	fire->index = 0;
}

t_animatable	*init_fire_animatable(
	void *mlx, int *w, int *h)
{
	t_animatable	*fire;

	fire = malloc(sizeof(t_animatable));
	if (fire == 0)
		error("Out of memory");
	init_fire_frames(fire, mlx, w, h);
	fire->count = 8;
	fire->index = 0;
	return (fire);
}
