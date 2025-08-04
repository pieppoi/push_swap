/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/31 23:19:35 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		i;

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	min = current->value;
	i = 0;
	while (i < stack->size)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
		i++;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		i;

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	max = current->value;
	i = 0;
	while (i < stack->size)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
		i++;
	}
	return (max);
}

int	get_position(t_stack *stack, int value)
{
	t_node	*current;
	int		position;
	int		i;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	position = 0;
	i = 0;
	while (i < stack->size)
	{
		if (current->value == value)
			return (position);
		current = current->next;
		position++;
		i++;
	}
	return (-1);
}

void	update_min_max(t_stack *stack)
{
	if (!stack || !stack->head)
		return ;
	stack->min = get_min(stack);
	stack->max = get_max(stack);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;
	int		i;

	if (!stack || !stack->head || stack->size <= 1)
		return (1);
	current = stack->head;
	i = 0;
	while (i < stack->size - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}
