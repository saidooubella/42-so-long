/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init___.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:16:11 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 11:16:15 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"
#include "utils.h"

static void	init_run_normal_frames(
	t_sprite *run, void *mlx, int *w, int *h)
{
	run->normal = malloc(sizeof(void *) * 10);
	if (run->normal == 0)
		error("Out of memory");
	run->normal[0] = load_xpm_file(mlx, "img/run__000.xpm", w, h);
	run->normal[1] = load_xpm_file(mlx, "img/run__001.xpm", w, h);
	run->normal[2] = load_xpm_file(mlx, "img/run__002.xpm", w, h);
	run->normal[3] = load_xpm_file(mlx, "img/run__003.xpm", w, h);
	run->normal[4] = load_xpm_file(mlx, "img/run__004.xpm", w, h);
	run->normal[5] = load_xpm_file(mlx, "img/run__005.xpm", w, h);
	run->normal[6] = load_xpm_file(mlx, "img/run__006.xpm", w, h);
	run->normal[7] = load_xpm_file(mlx, "img/run__007.xpm", w, h);
	run->normal[8] = load_xpm_file(mlx, "img/run__008.xpm", w, h);
	run->normal[9] = load_xpm_file(mlx, "img/run__009.xpm", w, h);
}

static void	init_run_reverse_frames(
	t_sprite *run, void *mlx, int *w, int *h)
{
	run->reverse = malloc(sizeof(void *) * 10);
	if (run->reverse == 0)
		error("Out of memory");
	run->reverse[0] = load_xpm_file(mlx, "img/run__rev__000.xpm", w, h);
	run->reverse[1] = load_xpm_file(mlx, "img/run__rev__001.xpm", w, h);
	run->reverse[2] = load_xpm_file(mlx, "img/run__rev__002.xpm", w, h);
	run->reverse[3] = load_xpm_file(mlx, "img/run__rev__003.xpm", w, h);
	run->reverse[4] = load_xpm_file(mlx, "img/run__rev__004.xpm", w, h);
	run->reverse[5] = load_xpm_file(mlx, "img/run__rev__005.xpm", w, h);
	run->reverse[6] = load_xpm_file(mlx, "img/run__rev__006.xpm", w, h);
	run->reverse[7] = load_xpm_file(mlx, "img/run__rev__007.xpm", w, h);
	run->reverse[8] = load_xpm_file(mlx, "img/run__rev__008.xpm", w, h);
	run->reverse[9] = load_xpm_file(mlx, "img/run__rev__009.xpm", w, h);
}

t_sprite	*init_run_sprite(
	void *mlx, int *w, int *h)
{
	t_sprite	*run;

	run = malloc(sizeof(t_sprite));
	if (run == 0)
		error("Out of memory");
	init_run_normal_frames(run, mlx, w, h);
	init_run_reverse_frames(run, mlx, w, h);
	run->count = 10;
	return (run);
}
