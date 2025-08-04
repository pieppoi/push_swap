/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/04 05:11:16 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*check;
	int		i;
	int		j;

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	i = 0;
	while (i < stack->size)
	{
		check = current->next;
		j = i + 1;
		while (j < stack->size)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
			j++;
		}
		current = current->next;
		i++;
	}
	return (0);
}
