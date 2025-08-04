/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/31 22:56:14 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	if (!stacks || !stacks->stack_a || !stacks->stack_a->head
		|| stacks->stack_a->size < 2)
		return ;
	stacks->stack_a->head = stacks->stack_a->head->next;
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_stacks *stacks)
{
	if (!stacks || !stacks->stack_a || !stacks->stack_a->head
		|| stacks->stack_a->size < 2)
		return ;
	stacks->stack_a->head = stacks->stack_a->head->prev;
	ft_putstr_fd("rra\n", 1);
}
