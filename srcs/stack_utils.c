/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/31 23:23:27 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (!stack || !stack->head)
		return (0);
	temp = stack->head;
	value = temp->value;
	if (stack->head->next == stack->head)
		stack->head = NULL;
	else
	{
		stack->head->prev->next = stack->head->next;
		stack->head->next->prev = stack->head->prev;
		stack->head = stack->head->next;
	}
	free(temp);
	stack->size--;
	return (value);
}

int	peek(t_stack *stack)
{
	if (!stack || !stack->head)
		return (0);
	return (stack->head->value);
}

int	is_empty(t_stack *stack)
{
	return (!stack || !stack->head);
}

void	move_to_top(t_stack *stack, int position)
{
	int	mid;
	int	i;

	if (!stack || !stack->head || position <= 0)
		return ;
	mid = stack->size / 2;
	if (position <= mid)
	{
		i = 0;
		while (i < position)
		{
			stack->head = stack->head->next;
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < stack->size - position)
		{
			stack->head = stack->head->prev;
			i++;
		}
	}
}
