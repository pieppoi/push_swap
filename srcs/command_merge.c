/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/01/27 10:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_operations(t_stacks *stacks)
{
	t_command	*current;

	current = stacks->commands;
	while (current && current->next)
	{
		if (merge_swap_operations(current))
			continue ;
		if (merge_rotate_operations(current))
			continue ;
		if (merge_reverse_rotate_operations(current))
			continue ;
		current = current->next;
	}
}

int	merge_swap_operations(t_command *current)
{
	t_command	*next;

	next = current->next;
	if ((ft_strncmp(current->cmd, "sa", 2) == 0 &&
		ft_strncmp(next->cmd, "sb", 2) == 0) ||
		(ft_strncmp(current->cmd, "sb", 2) == 0 &&
		ft_strncmp(next->cmd, "sa", 2) == 0))
	{
		free(current->cmd);
		current->cmd = ft_strdup("ss");
		remove_next_command(current);
		return (1);
	}
	return (0);
}

int	merge_rotate_operations(t_command *current)
{
	t_command	*next;

	next = current->next;
	if ((ft_strncmp(current->cmd, "ra", 2) == 0 &&
		ft_strncmp(next->cmd, "rb", 2) == 0) ||
		(ft_strncmp(current->cmd, "rb", 2) == 0 &&
		ft_strncmp(next->cmd, "ra", 2) == 0))
	{
		free(current->cmd);
		current->cmd = ft_strdup("rr");
		remove_next_command(current);
		return (1);
	}
	return (0);
}

int	merge_reverse_rotate_operations(t_command *current)
{
	t_command	*next;

	next = current->next;
	if ((ft_strncmp(current->cmd, "rra", 3) == 0 &&
		ft_strncmp(next->cmd, "rrb", 3) == 0) ||
		(ft_strncmp(current->cmd, "rrb", 3) == 0 &&
		ft_strncmp(next->cmd, "rra", 3) == 0))
	{
		free(current->cmd);
		current->cmd = ft_strdup("rrr");
		remove_next_command(current);
		return (1);
	}
	return (0);
}