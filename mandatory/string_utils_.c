/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:58:40 by soubella          #+#    #+#             */
/*   Updated: 2022/10/29 10:04:53 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "string_utils.h"
#include "utils.h"

int	string_ends_not_only_with(char *string, char *suffix)
{
	size_t	string_len;
	size_t	suffix_len;
	size_t	index;

	string_len = string_length(string);
	suffix_len = string_length(suffix);
	if (suffix_len + 1 > string_len)
		return (0);
	string += (string_len - suffix_len);
	index = -1;
	while (++index < suffix_len)
		if (string[index] != suffix[index])
			return (0);
	return (1);
}
