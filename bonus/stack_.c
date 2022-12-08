/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:46:22 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 11:46:35 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "stack.h"

int	stack_contains(t_stack *stack, size_t x, size_t y)
{
	while (stack)
	{
		if (stack->x == x && stack->y == y)
			return (1);
		stack = stack->next;
	}
	return (0);
}
