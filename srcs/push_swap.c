/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/05 04:50:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_single_arg(char *arg, t_stacks *stacks)
{
	char	**numbers;
	int		i;
	int		num;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]))
		{
			free_array(numbers);
			return (0);
		}
		num = ft_atoi(numbers[i]);
		push(stacks->stack_a, num);
		i++;
	}
	free_array(numbers);
	return (1);
}

static int	parse_multiple_args(int argc, char **argv, t_stacks *stacks)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		num = ft_atoi(argv[i]);
		push(stacks->stack_a, num);
		i++;
	}
	return (1);
}

static void	reverse_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	if (stack->size <= 1)
		return ;
	current = stack->head;
	while (current)
	{
		temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		current = temp;
	}
	temp = stack->head;
	stack->head = stack->tail;
	stack->tail = temp;
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		return (0);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (1);
	stacks->stack_a = create_stack();
	stacks->stack_b = create_stack();
	if (!stacks->stack_a || !stacks->stack_b)
	{
		error_exit(stacks);
		return (1);
	}
	if (argc == 2)
	{
		if (!parse_single_arg(argv[1], stacks))
		{
			error_exit(stacks);
			return (1);
		}
	}
	else
	{
		if (!parse_multiple_args(argc, argv, stacks))
		{
			error_exit(stacks);
			return (1);
		}
	}
	reverse_stack(stacks->stack_a);
	if (check_duplicates(stacks->stack_a))
	{
		error_exit(stacks);
		return (1);
	}
	if (!is_sorted(stacks->stack_a))
		sort_stack(stacks);
	clear_stack(stacks->stack_a);
	clear_stack(stacks->stack_b);
	free(stacks);
	return (0);
} 