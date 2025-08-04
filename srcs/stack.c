/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/05 04:50:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = create_node(value);
	if (!new_node)
		return ;
	if (is_empty(stack))
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->next = stack->head;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*node;
	int		value;

	if (is_empty(stack))
		return (0);
	node = stack->head;
	value = node->value;
	stack->head = node->next;
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	free(node);
	stack->size--;
	return (value);
}

void	clear_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

int	peek(t_stack *stack)
{
	if (is_empty(stack))
		return (0);
	return (stack->head->value);
}

void	print_stack(t_stack *stack, char name)
{
	t_node	*current;

	ft_putchar_fd(name, 1);
	ft_putstr_fd(": ", 1);
	current = stack->head;
	while (current)
	{
		ft_putnbr_fd(current->value, 1);
		ft_putchar_fd(' ', 1);
		current = current->next;
	}
	ft_putchar_fd('\n', 1);
} 