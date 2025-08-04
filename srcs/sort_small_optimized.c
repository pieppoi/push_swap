/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_optimized.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/01/27 10:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements_opt(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	if (stacks->stack_a->size < 3)
		return ;

	first = stacks->stack_a->head->value;
	second = stacks->stack_a->head->next->value;
	third = stacks->stack_a->head->next->next->value;
	
	if (first > second && second < third && third > first)
		sa_opt(stacks);
	else if (first > second && second > third)
	{
		sa_opt(stacks);
		rra_opt(stacks);
	}
	else if (first < second && second > third && third < first)
		rra_opt(stacks);
	else if (first > second && second < third && third < first)
		ra_opt(stacks);
	else if (first < second && second > third && third > first)
	{
		sa_opt(stacks);
		ra_opt(stacks);
	}
}

void	sort_six_or_less_opt(t_stacks *stacks)
{
	while (stacks->stack_a->size > 3)
	{
		push_smallest_to_b_opt(stacks);
	}
	sort_three_elements_opt(stacks);
	while (!is_empty(stacks->stack_b))
	{
		pa_opt(stacks);
	}
}

void	push_smallest_to_b_opt(t_stacks *stacks)
{
	int	min;
	int	position;

	min = get_min(stacks->stack_a);
	position = get_position(stacks->stack_a, min);
	while (position > 0)
	{
		if (position <= stacks->stack_a->size / 2)
		{
			ra_opt(stacks);
			position--;
		}
		else
		{
			rra_opt(stacks);
			position++;
			if (position >= stacks->stack_a->size)
				position = 0;
		}
	}
	pb_opt(stacks);
}