/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init__.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:14:44 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 11:14:50 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"
#include "utils.h"

static void	init_dead_normal_frames(
	t_sprite *dead, void *mlx, int *w, int *h)
{
	dead->normal = malloc(sizeof(void *) * 10);
	if (dead->normal == 0)
		error("Out of memory");
	dead->normal[0] = load_xpm_file(mlx, "img/dead__000.xpm", w, h);
	dead->normal[1] = load_xpm_file(mlx, "img/dead__001.xpm", w, h);
	dead->normal[2] = load_xpm_file(mlx, "img/dead__002.xpm", w, h);
	dead->normal[3] = load_xpm_file(mlx, "img/dead__003.xpm", w, h);
	dead->normal[4] = load_xpm_file(mlx, "img/dead__004.xpm", w, h);
	dead->normal[5] = load_xpm_file(mlx, "img/dead__005.xpm", w, h);
	dead->normal[6] = load_xpm_file(mlx, "img/dead__006.xpm", w, h);
	dead->normal[7] = load_xpm_file(mlx, "img/dead__007.xpm", w, h);
	dead->normal[8] = load_xpm_file(mlx, "img/dead__008.xpm", w, h);
	dead->normal[9] = load_xpm_file(mlx, "img/dead__009.xpm", w, h);
}

static void	init_dead_reverse_frames(
	t_sprite *dead, void *mlx, int *w, int *h)
{
	dead->reverse = malloc(sizeof(void *) * 10);
	if (dead->reverse == 0)
		error("Out of memory");
	dead->reverse[0] = load_xpm_file(mlx, "img/dead__rev__000.xpm", w, h);
	dead->reverse[1] = load_xpm_file(mlx, "img/dead__rev__001.xpm", w, h);
	dead->reverse[2] = load_xpm_file(mlx, "img/dead__rev__002.xpm", w, h);
	dead->reverse[3] = load_xpm_file(mlx, "img/dead__rev__003.xpm", w, h);
	dead->reverse[4] = load_xpm_file(mlx, "img/dead__rev__004.xpm", w, h);
	dead->reverse[5] = load_xpm_file(mlx, "img/dead__rev__005.xpm", w, h);
	dead->reverse[6] = load_xpm_file(mlx, "img/dead__rev__006.xpm", w, h);
	dead->reverse[7] = load_xpm_file(mlx, "img/dead__rev__007.xpm", w, h);
	dead->reverse[8] = load_xpm_file(mlx, "img/dead__rev__008.xpm", w, h);
	dead->reverse[9] = load_xpm_file(mlx, "img/dead__rev__009.xpm", w, h);
}

t_sprite	*init_dead_sprite(
	void *mlx, int *w, int *h)
{
	t_sprite	*dead;

	dead = malloc(sizeof(t_sprite));
	if (dead == 0)
		error("Out of memory");
	init_dead_normal_frames(dead, mlx, w, h);
	init_dead_reverse_frames(dead, mlx, w, h);
	dead->count = 10;
	return (dead);
}
