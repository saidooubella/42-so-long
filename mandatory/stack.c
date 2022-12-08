/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:45:26 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 12:37:15 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>

#include "stack.h"
#include "utils.h"

size_t	stack_size(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*stack_new(size_t x, size_t y)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	if (element == 0)
		error("Out of memory");
	element->next = 0;
	element->x = x;
	element->y = y;
	return (element);
}

void	stack_push(t_stack **stack, t_stack *new_node)
{
	new_node->next = *stack;
	*stack = new_node;
}

t_stack	*stack_pop(t_stack **stack)
{
	t_stack	*element;

	if (*stack == 0)
		error("Internal error");
	element = *stack;
	*stack = element->next;
	element->next = 0;
	return (element);
}

void	stack_free(t_stack **stack)
{
	t_stack	*stack_temp;
	t_stack	*next_temp;

	stack_temp = *stack;
	if (stack_temp == 0)
		return ;
	while (stack_temp)
	{
		next_temp = stack_temp->next;
		free(stack_temp);
		stack_temp = next_temp;
	}
	*stack = 0;
}
