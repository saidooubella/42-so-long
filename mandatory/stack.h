/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:42:40 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 12:35:07 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <sys/types.h>

typedef struct s_stack
{
	size_t			x;
	size_t			y;
	struct s_stack	*next;
}	t_stack;

int		stack_contains(t_stack *stack, size_t x, size_t y);
void	stack_push(t_stack **stack, t_stack *new_node);
t_stack	*stack_new(size_t x, size_t y);
t_stack	*stack_pop(t_stack **stack);
void	stack_free(t_stack **stack);
size_t	stack_size(t_stack *stack);

#endif
