/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/31 23:19:35 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stacks *stacks)
{
	if (stacks->stack_a->size <= 3)
		sort_three_or_less_opt(stacks);
	else if (stacks->stack_a->size <= 6)
		sort_six_or_less_opt(stacks);
	else
		sort_seven_or_more(stacks);
}

void	sort_three_or_less_opt(t_stacks *stacks)
{
	if (stacks->stack_a->size == 1)
		return ;
	else if (stacks->stack_a->size == 2)
	{
		if (stacks->stack_a->head->value > stacks->stack_a->head->next->value)
			sa_opt(stacks);
	}
	else if (stacks->stack_a->size == 3)
		sort_three_elements_opt(stacks);
}
