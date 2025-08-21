/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 01:27:36 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/08 12:25:57 by mkazuhik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack(t_stack *a, t_stack *b, int size)
{
	a->stack = malloc(size * sizeof(int));
	if (!a->stack)
		err_exit();
	a->size = 0;
	a->max = INT_MIN;
	a->min = INT_MAX;
	b->stack = malloc(size * sizeof(int));
	if (!b->stack)
	{
		free(a->stack);
		err_exit();
	}
	b->size = 0;
	b->max = INT_MIN;
	b->min = INT_MAX;
}

int	add_to_stack(t_stack *a, char *word)
{
	long	value;

	if (!is_digit_str(word))
		return (-1);
	value = ps_atoi(word);
	if (value == LONG_MAX)
		return (-1);
	a->stack[a->size] = (int)value;
	if (!is_unique(a))
		return (-1);
	if (a->max < a->stack[a->size])
		a->max = a->stack[a->size];
	if (a->min > a->stack[a->size])
		a->min = a->stack[a->size];
	return (0);
}