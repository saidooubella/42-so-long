/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:52:57 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 11:40:10 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>

#include "ft_printf.h"
#include "utils.h"
#include "mlx.h"

int	is_wall(char *string)
{
	while (*string)
		if (*string++ != '1')
			return (0);
	return (1);
}

int	has_char(char *string, char target)
{
	while (*string)
		if (*string++ == target)
			return (1);
	return (0);
}

int	index_of(char *string, char target)
{
	size_t	index;

	index = 0;
	while (string[index])
	{
		if (string[index] == target)
			return (index);
		index++;
	}
	return (index);
}

void	*load_xpm_file(void *mlx, char *filename, int *width, int *height)
{
	void	*image;

	image = mlx_xpm_file_to_image(mlx, filename, width, height);
	if (image == 0)
		error("Can't load '%s'", filename);
	return (image);
}

void	error(char *fmt, ...)
{
	va_list	args;

	ft_printf(STDERR_FILENO, "Error\n - ", 0);
	va_start(args, fmt);
	ft_printf_raw(STDERR_FILENO, fmt, args);
	va_end(args);
	ft_printf(STDERR_FILENO, ".\n", 0);
	exit(1);
}
