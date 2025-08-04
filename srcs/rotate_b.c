/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/31 22:56:08 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stacks *stacks)
{
	if (!stacks || !stacks->stack_b || !stacks->stack_b->head
		|| stacks->stack_b->size < 2)
		return ;
	stacks->stack_b->head = stacks->stack_b->head->next;
	ft_putstr_fd("rb\n", 1);
}

void	rrb(t_stacks *stacks)
{
	if (!stacks || !stacks->stack_b || !stacks->stack_b->head
		|| stacks->stack_b->size < 2)
		return ;
	stacks->stack_b->head = stacks->stack_b->head->prev;
	ft_putstr_fd("rrb\n", 1);
}

void	rr(t_stacks *stacks)
{
	if (stacks && stacks->stack_a && stacks->stack_a->head
		&& stacks->stack_a->size >= 2)
		stacks->stack_a->head = stacks->stack_a->head->next;
	if (stacks && stacks->stack_b && stacks->stack_b->head
		&& stacks->stack_b->size >= 2)
		stacks->stack_b->head = stacks->stack_b->head->next;
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_stacks *stacks)
{
	if (stacks && stacks->stack_a && stacks->stack_a->head
		&& stacks->stack_a->size >= 2)
		stacks->stack_a->head = stacks->stack_a->head->prev;
	if (stacks && stacks->stack_b && stacks->stack_b->head
		&& stacks->stack_b->size >= 2)
		stacks->stack_b->head = stacks->stack_b->head->prev;
	ft_putstr_fd("rrr\n", 1);
}
