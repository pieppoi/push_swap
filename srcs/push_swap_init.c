/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/01/16 10:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_from_split_args(t_stack *stack_a, char **split_args)
{
	int	i;
	int	count;

	count = 0;
	while (split_args[count])
		count++;
	i = count - 1;
	while (i >= 0)
	{
		push(stack_a, ft_atoi(split_args[i]));
		i--;
	}
}

void	init_stack_from_args(t_stack *stack_a, int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		push(stack_a, ft_atoi(argv[i]));
		i--;
	}
}
