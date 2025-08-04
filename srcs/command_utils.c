/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/01/27 10:00:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_next_command(t_command *current)
{
	t_command	*to_remove;

	if (!current || !current->next)
		return ;
	to_remove = current->next;
	current->next = to_remove->next;
	free(to_remove->cmd);
	free(to_remove);
}

void	remove_current_and_next(t_command **head, t_command *current)
{
	t_command	*to_remove1;
	t_command	*to_remove2;

	if (!head || !*head || !current || !current->next)
		return ;
	to_remove1 = current;
	to_remove2 = current->next;
	if (*head == current)
	{
		*head = to_remove2->next;
	}
	else
	{
		find_and_update_prev_link(head, current, to_remove2);
	}
	free(to_remove1->cmd);
	free(to_remove1);
	free(to_remove2->cmd);
	free(to_remove2);
}

void	find_and_update_prev_link(t_command **head, t_command *current,
	t_command *to_remove2)
{
	t_command	*prev;

	prev = *head;
	while (prev && prev->next != current)
		prev = prev->next;
	if (prev)
		prev->next = to_remove2->next;
}

void	remove_command_from_list(t_command **head, t_command *to_remove)
{
	t_command	*current;

	if (!head || !*head || !to_remove)
		return ;
	if (*head == to_remove)
	{
		*head = to_remove->next;
		free(to_remove->cmd);
		free(to_remove);
		return ;
	}
	current = *head;
	while (current && current->next != to_remove)
		current = current->next;
	if (current)
	{
		current->next = to_remove->next;
		free(to_remove->cmd);
		free(to_remove);
	}
}