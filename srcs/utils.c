/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/05 04:50:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	check_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack->head;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack->size <= 1)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	get_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (is_empty(stack))
		return (0);
	current = stack->head;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (is_empty(stack))
		return (0);
	current = stack->head;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int value)
{
	t_node	*current;
	int		position;

	if (is_empty(stack))
		return (-1);
	current = stack->head;
	position = 0;
	while (current)
	{
		if (current->value == value)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

int	get_pivot(t_stack *stack)
{
	t_node	*current;
	int		sum;
	int		count;

	if (is_empty(stack))
		return (0);
	current = stack->head;
	sum = 0;
	count = 0;
	while (current)
	{
		sum += current->value;
		count++;
		current = current->next;
	}
	return (sum / count);
}

void	error_exit(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->stack_a)
			clear_stack(stacks->stack_a);
		if (stacks->stack_b)
			clear_stack(stacks->stack_b);
		free(stacks);
	}
	ft_putstr_fd("Error\n", 2);
	exit(1);
} 