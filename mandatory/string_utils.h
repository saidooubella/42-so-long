/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:39:07 by soubella          #+#    #+#             */
/*   Updated: 2022/10/29 20:27:53 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

# include <sys/types.h>

int		string_ends_not_only_with(char *string, char *suffix);
char	*string_join(char const *s1, char const *s2);
char	*int_to_string(size_t number, char *base, int base_size);
size_t	string_length(const char *string);

#endif
