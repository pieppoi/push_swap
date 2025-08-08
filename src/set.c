/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 01:26:57 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/08 01:27:04 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_a_head(t_stack *a, int set_nb)
{
	int	index;

	index = find_index(a, set_nb);
	while (a->stack[0] != set_nb)
	{
		if (index < a->size / 2)
			rotate_ab(a, "ra\n");
		else
			reverse_rotate_ab(a, "rra\n");
	}
}

void	set_b_tail(t_stack *b, int set_nb)
{
	int	index;

	index = find_index(b, set_nb);
	while (set_nb != b->stack[b->size - 1])
	{
		if (index < b->size / 2)
			rotate_ab(b, "rb\n");
		else
			reverse_rotate_ab(b, "rrb\n");
	}
}

void	set_both_rotate(t_stack *a, t_stack *b, int b_nb, int a_nb)
{
	int	b_index;
	int	a_index;

	b_index = find_index(b, b_nb);
	a_index = find_index(a, a_nb);
	while (b_nb != b->stack[b->size - 1] && a->stack[0] != a_nb)
	{
		if (b_index < b->size / 2 && a_index < a->size / 2)
			rotate_rr(a, b);
		else if (b_index >= b->size / 2 && a_index >= a->size / 2)
			reverse_rotate_rrr(a, b);
		else
			break ;
	}
}
