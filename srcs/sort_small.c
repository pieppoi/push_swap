/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/04 05:09:32 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_or_less(t_stacks *stacks)
{
	if (stacks->stack_a->size == 1)
		return ;
	else if (stacks->stack_a->size == 2)
	{
		if (stacks->stack_a->head->value > stacks->stack_a->head->next->value)
			sa(stacks);
	}
	else if (stacks->stack_a->size == 3)
		sort_three_elements(stacks);
}

void	sort_six_or_less(t_stacks *stacks)
{
	while (stacks->stack_a->size > 3)
	{
		push_smallest_to_b(stacks);
	}
	sort_three_elements(stacks);
	while (!is_empty(stacks->stack_b))
	{
		pa(stacks);
	}
}

void	push_smallest_to_b(t_stacks *stacks)
{
	int	min;
	int	position;

	min = get_min(stacks->stack_a);
	position = get_position(stacks->stack_a, min);
	while (position > 0)
	{
		if (position <= stacks->stack_a->size / 2)
		{
			ra(stacks);
			position--;
		}
		else
		{
			rra(stacks);
			position++;
			if (position >= stacks->stack_a->size)
				position = 0;
		}
	}
	pb(stacks);
}

void	sort_three_elements(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = stacks->stack_a->head->value;
	second = stacks->stack_a->head->next->value;
	third = stacks->stack_a->head->next->next->value;
	if (first > second && second < third && third > first)
		sa(stacks);
	else if (first > second && second > third)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (first < second && second > third && third < first)
		rra(stacks);
	else if (first > second && second < third && third < first)
		ra(stacks);
	else if (first < second && second > third && third > first)
	{
		sa(stacks);
		ra(stacks);
	}
}
