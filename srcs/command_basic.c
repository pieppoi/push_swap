/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/01/27 10:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_command	*create_command(char *cmd)
{
	t_command	*new_cmd;

	new_cmd = (t_command *)malloc(sizeof(t_command));
	if (!new_cmd)
		return (NULL);
	new_cmd->cmd = ft_strdup(cmd);
	if (!new_cmd->cmd)
	{
		free(new_cmd);
		return (NULL);
	}
	new_cmd->next = NULL;
	return (new_cmd);
}

void	add_command(t_stacks *stacks, char *cmd)
{
	t_command	*new_cmd;
	t_command	*current;

	new_cmd = create_command(cmd);
	if (!new_cmd)
		return ;
	if (!stacks->commands)
	{
		stacks->commands = new_cmd;
		return ;
	}
	current = stacks->commands;
	while (current->next)
		current = current->next;
	current->next = new_cmd;
}

void	print_commands(t_stacks *stacks)
{
	t_command	*current;

	current = stacks->commands;
	while (current)
	{
		ft_putstr_fd(current->cmd, 1);
		ft_putchar_fd('\n', 1);
		current = current->next;
	}
}

void	free_commands(t_command *commands)
{
	t_command	*temp;

	while (commands)
	{
		temp = commands;
		commands = commands->next;
		free(temp->cmd);
		free(temp);
	}
}

void	optimize_commands(t_stacks *stacks)
{
	merge_operations(stacks);
	remove_opposite_operations(stacks);
}

void	merge_consecutive_operations(t_stacks *stacks)
{
	(void)stacks;
}