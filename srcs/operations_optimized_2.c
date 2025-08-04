/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_optimized_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/01/27 10:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_opt(t_stacks *stacks)
{
	if (!stacks || !stacks->stack_a || !stacks->stack_a->head ||
		stacks->stack_a->size < 2)
		return ;
	stacks->stack_a->head = stacks->stack_a->head->next;
	add_command(stacks, "ra");
}

void	rb_opt(t_stacks *stacks)
{
	if (!stacks || !stacks->stack_b || !stacks->stack_b->head ||
		stacks->stack_b->size < 2)
		return ;
	stacks->stack_b->head = stacks->stack_b->head->next;
	add_command(stacks, "rb");
}

void	rr_opt(t_stacks *stacks)
{
	rr(stacks);
	add_command(stacks, "rr");
}

void	rra_opt(t_stacks *stacks)
{
	if (!stacks || !stacks->stack_a || !stacks->stack_a->head ||
		stacks->stack_a->size < 2)
		return ;
	stacks->stack_a->head = stacks->stack_a->head->prev;
	add_command(stacks, "rra");
}

void	rrb_opt(t_stacks *stacks)
{
	if (!stacks || !stacks->stack_b || !stacks->stack_b->head ||
		stacks->stack_b->size < 2)
		return ;
	stacks->stack_b->head = stacks->stack_b->head->prev;
	add_command(stacks, "rrb");
}