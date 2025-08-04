/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/04 05:08:49 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	cleanup_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->stack_a)
			clear_stack(stacks->stack_a);
		if (stacks->stack_b)
			clear_stack(stacks->stack_b);
		if (stacks->commands)
			free_commands(stacks->commands);
		free(stacks);
	}
}

static void	process_and_sort(t_stacks *stacks, char **parsed_args)
{
	if (check_duplicates(stacks->stack_a))
	{
		cleanup_stacks(stacks);
		if (parsed_args)
			free_split_args(parsed_args);
		handle_error();
	}
	if (!is_sorted(stacks->stack_a))
	{
		sort_stack(stacks);
		optimize_commands(stacks);
		print_commands(stacks);
	}
}

static void	initialize_stacks(t_stacks **stacks, char **parsed_args)
{
	*stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!*stacks)
	{
		if (parsed_args)
			free_split_args(parsed_args);
		handle_error();
	}
	(*stacks)->stack_a = create_stack();
	(*stacks)->stack_b = create_stack();
	(*stacks)->commands = NULL;
	if (!(*stacks)->stack_a || !(*stacks)->stack_b)
	{
		cleanup_stacks(*stacks);
		if (parsed_args)
			free_split_args(parsed_args);
		handle_error();
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**parsed_args;
	int			new_argc;

	if (argc < 2)
		return (0);
	if (!validate_input_with_parsing(argc, argv, &parsed_args, &new_argc))
		handle_error();
	initialize_stacks(&stacks, parsed_args);
	if (parsed_args)
		init_stack_from_split_args(stacks->stack_a, parsed_args);
	else
		init_stack_from_args(stacks->stack_a, argc, argv);
	process_and_sort(stacks, parsed_args);
	cleanup_stacks(stacks);
	if (parsed_args)
		free_split_args(parsed_args);
	return (0);
}
