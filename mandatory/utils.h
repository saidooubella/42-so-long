/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:59:18 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 11:41:50 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	*load_xpm_file(void *mlx, char *filename, int *width, int *height);
int		index_of(char *string, char target);
int		is_wall(char *string);
int		ft_strchr(const char *str, char ch);
int		has_only(char *string, char *charset);
int		char_count(char *string, char target);
int		has_char(char *string, char target);
void	error(char *fmt, ...);

#endif
