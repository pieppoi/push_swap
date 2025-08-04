/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/31 22:52:58 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!stack || !stack->head || stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	if (first == second)
		return ;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	sa(t_stacks *stacks)
{
	if (!stacks || !stacks->stack_a)
		return ;
	swap_stack(stacks->stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stacks *stacks)
{
	if (!stacks || !stacks->stack_b)
		return ;
	swap_stack(stacks->stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stacks *stacks)
{
	swap_stack(stacks->stack_a);
	swap_stack(stacks->stack_b);
	ft_putstr_fd("ss\n", 1);
}
