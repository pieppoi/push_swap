/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/31 23:46:25 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_min_max(t_stack *stack, int value)
{
	if (value > stack->max)
		stack->max = value;
	if (value < stack->min)
		stack->min = value;
}

static void	insert_node_empty_stack(t_stack *stack, t_node *new_node)
{
	new_node->next = new_node;
	new_node->prev = new_node;
	stack->head = new_node;
}

static void	insert_node_non_empty_stack(t_stack *stack, t_node *new_node)
{
	new_node->next = stack->head;
	new_node->prev = stack->head->prev;
	stack->head->prev->next = new_node;
	stack->head->prev = new_node;
	stack->head = new_node;
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		return ;
	new_node = create_node(value);
	if (!new_node)
		return ;
	if (stack->head == NULL)
		insert_node_empty_stack(stack, new_node);
	else
		insert_node_non_empty_stack(stack, new_node);
	stack->size++;
	update_min_max(stack, value);
}

void	clear_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->head;
	while (current && stack->size > 0)
	{
		next = current->next;
		free(current);
		current = next;
		stack->size--;
		if (current == stack->head)
			break ;
	}
	stack->head = NULL;
	free(stack);
}
