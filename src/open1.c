/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 01:27:49 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/08 11:16:28 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_ab(t_stack *stack, char *str)
{
	int	temp;

	temp = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = temp;
	if (str != NULL)
		ft_putstr_fd(str, 1);
}

void	swap_ss(t_stack *a, t_stack *b)
{
	swap_ab(a, NULL);
	swap_ab(b, NULL);
	ft_putstr_fd("ss\n", 1);
}

void	push_arg1_to_arg2(t_stack *from, t_stack *to, char *str)
{
	int	temp;
	int	i;

	if (from->size == 0)
		return ;
	temp = from->stack[0];
	i = 0;
	while (i < from->size - 1)
	{
		from->stack[i] = from->stack[i + 1];
		i++;
	}
	i = to->size;
	while (i)
	{
		to->stack[i] = to->stack[i - 1];
		i--;
	}
	to->stack[0] = temp;
	to->size += 1;
	from->size -= 1;
	updata_minmax(from, to, temp);
	ft_putstr_fd(str, 1);
}

void	updata_minmax(t_stack *from, t_stack *to, int nb)
{
	if (from->max == nb)
		from->max = find_max(from);
	if (from->min == nb)
		from->min = find_min(from);
	if (to->max < nb)
		to->max = nb;
	if (to->min > nb)
		to->min = nb;
}
