/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/31 22:50:56 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	int	value;

	if (!stacks || !stacks->stack_b || !stacks->stack_b->head)
		return ;
	value = pop(stacks->stack_b);
	push(stacks->stack_a, value);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stacks *stacks)
{
	int	value;

	if (!stacks || !stacks->stack_a || !stacks->stack_a->head)
		return ;
	value = pop(stacks->stack_a);
	push(stacks->stack_b, value);
	ft_putstr_fd("pb\n", 1);
}
