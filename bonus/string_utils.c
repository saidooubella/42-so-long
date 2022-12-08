/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:59:59 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 17:31:23 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>

#include "utils.h"

size_t	string_length(const char *string)
{
	size_t	size;

	size = -1;
	while (string[++size])
		;
	return (size);
}

static int	digits_count(unsigned int number, int base)
{
	int	count;

	if (number == 0)
		return (1);
	count = 0;
	while (number != 0)
	{
		number /= base;
		count++;
	}
	return (count);
}

char	*int_to_string(size_t number, char *base, int base_size)
{
	char	*result;
	int		size;
	int		i;

	size = digits_count(number, base_size) + 1;
	result = malloc(sizeof(char) * size);
	if (result == 0)
		error("Out of memory");
	i = size - 2;
	while (i >= 0)
	{
		result[i--] = base[number % base_size];
		number /= base_size;
	}
	result[size - 1] = 0;
	return (result);
}

static char	*append(char *s1, char const *s2)
{
	while (*s2)
		*s1++ = *s2++;
	return (s1);
}

char	*string_join(char const *s1, char const *s2)
{
	size_t	size;
	char	*res;

	size = string_length(s1) + string_length(s2);
	res = malloc(size + 1);
	if (res == 0)
		error("Out of memory");
	*append(append(res, s1), s2) = 0;
	return (res);
}
