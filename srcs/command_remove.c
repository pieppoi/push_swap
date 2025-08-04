/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/01/27 10:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_opposite_operations(t_stacks *stacks)
{
	t_command	*current;

	current = stacks->commands;
	while (current && current->next)
	{
		if (check_and_remove_push_ops(stacks, current))
		{
			current = stacks->commands;
			continue ;
		}
		if (check_and_remove_rotate_ops(stacks, current))
		{
			current = stacks->commands;
			continue ;
		}
		current = current->next;
	}
}

int	check_and_remove_push_ops(t_stacks *stacks, t_command *current)
{
	t_command	*next;

	next = current->next;
	if ((ft_strncmp(current->cmd, "pa", 2) == 0 &&
		ft_strncmp(next->cmd, "pb", 2) == 0) ||
		(ft_strncmp(current->cmd, "pb", 2) == 0 &&
		ft_strncmp(next->cmd, "pa", 2) == 0))
	{
		remove_current_and_next(&stacks->commands, current);
		return (1);
	}
	return (0);
}

int	check_and_remove_rotate_ops(t_stacks *stacks, t_command *current)
{
	t_command	*next;

	next = current->next;
	if (check_ra_rra_pair(current, next) || check_rb_rrb_pair(current, next))
	{
		remove_current_and_next(&stacks->commands, current);
		return (1);
	}
	return (0);
}

int	check_ra_rra_pair(t_command *current, t_command *next)
{
	return ((ft_strncmp(current->cmd, "ra", 2) == 0 &&
		ft_strncmp(next->cmd, "rra", 3) == 0) ||
		(ft_strncmp(current->cmd, "rra", 3) == 0 &&
		ft_strncmp(next->cmd, "ra", 2) == 0));
}

int	check_rb_rrb_pair(t_command *current, t_command *next)
{
	return ((ft_strncmp(current->cmd, "rb", 2) == 0 &&
		ft_strncmp(next->cmd, "rrb", 3) == 0) ||
		(ft_strncmp(current->cmd, "rrb", 3) == 0 &&
		ft_strncmp(next->cmd, "rb", 2) == 0));
}