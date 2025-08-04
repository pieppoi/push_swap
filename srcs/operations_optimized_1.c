/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_optimized_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/01/27 10:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_opt(t_stacks *stacks)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!stacks || !stacks->stack_a || !stacks->stack_a->head ||
		!stacks->stack_a->head->next)
		return ;
	first = stacks->stack_a->head;
	second = stacks->stack_a->head->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	add_command(stacks, "sa");
}

void	sb_opt(t_stacks *stacks)
{
	sb(stacks);
	add_command(stacks, "sb");
}

void	ss_opt(t_stacks *stacks)
{
	ss(stacks);
	add_command(stacks, "ss");
}

void	pa_opt(t_stacks *stacks)
{
	int	value;

	if (!stacks || !stacks->stack_b || !stacks->stack_b->head)
		return ;
	value = pop(stacks->stack_b);
	push(stacks->stack_a, value);
	add_command(stacks, "pa");
}

void	pb_opt(t_stacks *stacks)
{
	int	value;

	if (!stacks || !stacks->stack_a || !stacks->stack_a->head)
		return ;
	value = pop(stacks->stack_a);
	push(stacks->stack_b, value);
	add_command(stacks, "pb");
}