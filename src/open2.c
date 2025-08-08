/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 01:27:57 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/08 11:16:41 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_ab(t_stack *stack, char *str)
{
	int	temp;
	int	i;

	temp = stack->stack[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[stack->size - 1] = temp;
	if (str != NULL)
		ft_putstr_fd(str, 1);
}

void	rotate_rr(t_stack *a, t_stack *b)
{
	rotate_ab(a, NULL);
	rotate_ab(b, NULL);
	ft_putstr_fd("rr\n", 1);
}

void	reverse_rotate_ab(t_stack *stack, char *str)
{
	int	temp;
	int	i;

	temp = stack->stack[stack->size - 1];
	i = stack->size - 1;
	while (i)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[0] = temp;
	if (str != NULL)
		ft_putstr_fd(str, 1);
}

void	reverse_rotate_rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_ab(a, NULL);
	reverse_rotate_ab(b, NULL);
	ft_putstr_fd("rrr\n", 1);
}
