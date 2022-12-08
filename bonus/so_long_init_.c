/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:14:00 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 11:14:07 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"
#include "utils.h"

static void	init_idle_normal_frames(
	t_sprite *idle, void *mlx, int *w, int *h)
{
	idle->normal = malloc(sizeof(void *) * 10);
	if (idle->normal == 0)
		error("Out of memory");
	idle->normal[0] = load_xpm_file(mlx, "img/idle__000.xpm", w, h);
	idle->normal[1] = load_xpm_file(mlx, "img/idle__001.xpm", w, h);
	idle->normal[2] = load_xpm_file(mlx, "img/idle__002.xpm", w, h);
	idle->normal[3] = load_xpm_file(mlx, "img/idle__003.xpm", w, h);
	idle->normal[4] = load_xpm_file(mlx, "img/idle__004.xpm", w, h);
	idle->normal[5] = load_xpm_file(mlx, "img/idle__005.xpm", w, h);
	idle->normal[6] = load_xpm_file(mlx, "img/idle__006.xpm", w, h);
	idle->normal[7] = load_xpm_file(mlx, "img/idle__007.xpm", w, h);
	idle->normal[8] = load_xpm_file(mlx, "img/idle__008.xpm", w, h);
	idle->normal[9] = load_xpm_file(mlx, "img/idle__009.xpm", w, h);
}

static void	init_idle_reverse_frames(
	t_sprite *idle, void *mlx, int *w, int *h)
{
	idle->reverse = malloc(sizeof(void *) * 10);
	if (idle->reverse == 0)
		error("Out of memory");
	idle->reverse[0] = load_xpm_file(mlx, "img/idle__rev__000.xpm", w, h);
	idle->reverse[1] = load_xpm_file(mlx, "img/idle__rev__001.xpm", w, h);
	idle->reverse[2] = load_xpm_file(mlx, "img/idle__rev__002.xpm", w, h);
	idle->reverse[3] = load_xpm_file(mlx, "img/idle__rev__003.xpm", w, h);
	idle->reverse[4] = load_xpm_file(mlx, "img/idle__rev__004.xpm", w, h);
	idle->reverse[5] = load_xpm_file(mlx, "img/idle__rev__005.xpm", w, h);
	idle->reverse[6] = load_xpm_file(mlx, "img/idle__rev__006.xpm", w, h);
	idle->reverse[7] = load_xpm_file(mlx, "img/idle__rev__007.xpm", w, h);
	idle->reverse[8] = load_xpm_file(mlx, "img/idle__rev__008.xpm", w, h);
	idle->reverse[9] = load_xpm_file(mlx, "img/idle__rev__009.xpm", w, h);
}

t_sprite	*init_idle_sprite(
	void *mlx, int *w, int *h)
{
	t_sprite	*idle;

	idle = malloc(sizeof(t_sprite));
	if (idle == 0)
		error("Out of memory");
	init_idle_normal_frames(idle, mlx, w, h);
	init_idle_reverse_frames(idle, mlx, w, h);
	idle->count = 10;
	return (idle);
}
