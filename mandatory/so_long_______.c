/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_______.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:51:17 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 14:35:40 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "string_utils.h"
#include "so_long.h"
#include "stack.h"

static void	push_valid_coordinates(
	t_map *m, t_stack *n, t_stack *visited, t_stack **stack)
{
	if (map_in_range(m, n->x, n->y + 1) && m->map[n->x][n->y + 1] != '1')
		if (!stack_contains(visited, n->x, n->y + 1))
			stack_push(stack, stack_new(n->x, n->y + 1));
	if (map_in_range(m, n->x + 1, n->y) && m->map[n->x + 1][n->y] != '1')
		if (!stack_contains(visited, n->x + 1, n->y))
			stack_push(stack, stack_new(n->x + 1, n->y));
	if (map_in_range(m, n->x, n->y - 1) && m->map[n->x][n->y - 1] != '1')
		if (!stack_contains(visited, n->x, n->y - 1))
			stack_push(stack, stack_new(n->x, n->y - 1));
	if (map_in_range(m, n->x - 1, n->y) && m->map[n->x - 1][n->y] != '1')
		if (!stack_contains(visited, n->x - 1, n->y))
			stack_push(stack, stack_new(n->x - 1, n->y));
}

static int	handle_coordinate(
	t_map *map, int *found, t_stack **visited, t_stack **stack)
{
	t_stack	*temp;

	temp = stack_pop(stack);
	if (map->map[temp->x][temp->y] == 'E')
	{
		stack_push(visited, temp);
		*found = 1;
		return (1);
	}
	push_valid_coordinates(map, temp, *visited, stack);
	stack_push(visited, temp);
	return (0);
}

void	init_parsing_state(t_parsing_state *state, int argc, char *filename)
{
	state->prev_is_wall = 0;
	state->line_number = 1;
	state->has_player = 0;
	state->keys_count = 0;
	state->has_exit = 0;
	state->player_x = 0;
	state->player_y = 0;
	validate_arguments(argc);
	state->filename = filename;
	state->line = validate_and_open_file(
			state->filename, &state->file_state, &state->fd, 1);
	state->map_width = string_length(state->line);
	state->map_height = 0;
}

int	validate_path(t_map *map, size_t player_x, size_t player_y)
{
	t_stack	*stack;
	t_stack	*visited;
	int		found;

	visited = 0;
	found = 0;
	stack = 0;
	stack_push(&stack, stack_new(player_x, player_y));
	while (stack_size(stack))
		if (handle_coordinate(map, &found, &visited, &stack))
			break ;
	stack_free(&visited);
	stack_free(&stack);
	return (found);
}
