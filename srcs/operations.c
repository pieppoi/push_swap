/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/05 04:50:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (stacks->stack_a->size < 2)
		return ;
	first = stacks->stack_a->head;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stacks *stacks)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (stacks->stack_b->size < 2)
		return ;
	first = stacks->stack_b->head;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stacks *stacks)
{
	int	value;

	if (is_empty(stacks->stack_b))
		return ;
	value = pop(stacks->stack_b);
	push(stacks->stack_a, value);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stacks *stacks)
{
	int	value;

	if (is_empty(stacks->stack_a))
		return ;
	value = pop(stacks->stack_a);
	push(stacks->stack_b, value);
	ft_putstr_fd("pb\n", 1);
}

void	ra(t_stacks *stacks)
{
	t_node	*first;

	if (stacks->stack_a->size < 2)
		return ;
	first = stacks->stack_a->head;
	stacks->stack_a->head = first->next;
	stacks->stack_a->head->prev = NULL;
	first->next = NULL;
	first->prev = stacks->stack_a->tail;
	stacks->stack_a->tail->next = first;
	stacks->stack_a->tail = first;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stacks *stacks)
{
	t_node	*first;

	if (stacks->stack_b->size < 2)
		return ;
	first = stacks->stack_b->head;
	stacks->stack_b->head = first->next;
	stacks->stack_b->head->prev = NULL;
	first->next = NULL;
	first->prev = stacks->stack_b->tail;
	stacks->stack_b->tail->next = first;
	stacks->stack_b->tail = first;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_stacks *stacks)
{
	t_node	*last;

	if (stacks->stack_a->size < 2)
		return ;
	last = stacks->stack_a->tail;
	stacks->stack_a->tail = last->prev;
	stacks->stack_a->tail->next = NULL;
	last->prev = NULL;
	last->next = stacks->stack_a->head;
	stacks->stack_a->head->prev = last;
	stacks->stack_a->head = last;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stacks *stacks)
{
	t_node	*last;

	if (stacks->stack_b->size < 2)
		return ;
	last = stacks->stack_b->tail;
	stacks->stack_b->tail = last->prev;
	stacks->stack_b->tail->next = NULL;
	last->prev = NULL;
	last->next = stacks->stack_b->head;
	stacks->stack_b->head->prev = last;
	stacks->stack_b->head = last;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
	ft_putstr_fd("rrr\n", 1);
} 