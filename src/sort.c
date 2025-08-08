/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 01:28:08 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/08 01:28:10 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack *stack)
{
	if (is_sorted(stack))
		return ;
	if (stack->size == 2)
		swap_ab(stack, "sa\n");
	else if (stack->stack[0] < stack->stack[1])
	{
		reverse_rotate_ab(stack, "rra\n");
		if (!is_sorted(stack))
			swap_ab(stack, "sa\n");
	}
	else if (stack->stack[1] < stack->stack[2])
	{
		if (stack->stack[0] < stack->stack[2])
			swap_ab(stack, "sa\n");
		else
			rotate_ab(stack, "ra\n");
	}
	else
	{
		rotate_ab(stack, "ra\n");
		swap_ab(stack, "sa\n");
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	push_arg1_to_arg2(a, b, "pb\n");
	push_arg1_to_arg2(a, b, "pb\n");
	while (1)
	{
		if (a->size < 4)
			break ;
		set_stack(a, b, find_lcost_nb(a, b));
		push_arg1_to_arg2(a, b, "pb\n");
	}
	sort_three(a);
	push_a_phase(a, b);
}

void	push_a_phase(t_stack *a, t_stack *b)
{
	int	min_index;

	while (b->size != 0)
	{
		if ((a->stack[0] > b->stack[0] && a->stack[a->size - 1] < b->stack[0])
			|| (b->stack[0] < a->min && a->min == a->stack[0])
			|| (b->stack[0] > a->max && a->max == a->stack[a->size - 1]))
			push_arg1_to_arg2(b, a, "pa\n");
		else
			reverse_rotate_ab(a, "rra\n");
	}
	min_index = find_index(a, a->min);
	while (!is_sorted(a))
	{
		if (min_index < a->size / 2)
			rotate_ab(a, "ra\n");
		else
			reverse_rotate_ab(a, "rra\n");
	}
}

void	set_stack(t_stack *a, t_stack *b, int a_nb)
{
	int	i;
	int	b_nb;

	if (a_nb < b->min || a_nb > b->max)
	{
		set_both_rotate(a, b, b->min, a_nb);
		set_b_tail(b, b->min);
		set_a_head(a, a_nb);
		return ;
	}
	i = 0;
	while (i < b->size)
	{
		if (b->stack[i] > a_nb && b->stack[(i + 1) % b->size] < a_nb)
		{
			b_nb = b->stack[i];
			set_both_rotate(a, b, b_nb, a_nb);
			set_b_tail(b, b_nb);
			set_a_head(a, a_nb);
			break ;
		}
		i++;
	}
}

bool	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (false);
		i++;
	}
	return (true);
}
