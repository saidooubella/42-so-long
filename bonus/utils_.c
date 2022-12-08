/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:41:08 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 12:37:29 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "string_utils.h"

int	ft_strchr(const char *str, char ch)
{
	size_t	length;
	size_t	index;

	length = string_length(str) + 1;
	index = 0;
	while (index < length)
	{
		if (str[index] == (char)ch)
			return (1);
		index++;
	}
	return (0);
}

int	has_only(char *string, char *charset)
{
	char	*temp;

	while (*string)
	{
		temp = charset;
		if (!ft_strchr(charset, *string))
			return (0);
		string++;
	}
	return (1);
}

int	char_count(char *string, char target)
{
	size_t	count;

	count = 0;
	while (*string)
		if (*string++ == target)
			count++;
	return (count);
}
