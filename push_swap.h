/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/31 23:45:57 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int					value;
	struct s_node		*next;
	struct s_node		*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
	int		max;
	int		min;
}	t_stack;

typedef struct s_command
{
	char				*cmd;
	struct s_command	*next;
}	t_command;

typedef struct s_stacks
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_command	*commands;
}	t_stacks;

t_stack	*create_stack(void);
t_node	*create_node(int value);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	clear_stack(t_stack *stack);
int		is_empty(t_stack *stack);
int		peek(t_stack *stack);
void	move_to_top(t_stack *stack, int position);

void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

// validation.c
int		validate_input(int argc, char **argv);
int		validate_input_with_parsing(int argc, char **argv, char ***parsed_args,
			int *new_argc);
int		check_duplicates(t_stack *stack);

// validation_utils.c
int		check_overflow(int sign, long num);
int		parse_sign_and_skip(const char *str, int *i);
int		is_valid_integer_range(const char *str);
int		validate_single_arg(char *arg);
int		validate_split_arguments(char **split_args);

// parsing_utils.c
int		count_numbers_in_string(char *str);
char	**parse_single_argument(char *arg, int *new_argc);
void	free_split_args(char **args);
int		process_single_string_argument(char *arg, char ***parsed_args,
			int *new_argc);

// push_swap_init.c
void	init_stack_from_split_args(t_stack *stack_a, char **split_args);
void	init_stack_from_args(t_stack *stack_a, int argc, char **argv);

void	sort_stack(t_stacks *stacks);
void	sort_three_or_less(t_stacks *stacks);
void	sort_three_or_less_opt(t_stacks *stacks);
void	sort_six_or_less(t_stacks *stacks);
void	sort_seven_or_more(t_stacks *stacks);
void	sort_three_elements(t_stacks *stacks);
void	push_smallest_to_b(t_stacks *stacks);
void	quick_sort_large(t_stacks *stacks, int size);
void	chunk_sort(t_stacks *stacks, int size);
void	small_chunk_sort(t_stacks *stacks, int size);
void	large_chunk_sort(t_stacks *stacks, int size);
void	push_two_chunks_to_b(t_stacks *stacks, int pivot1, int pivot2);
void	push_back_sorted(t_stacks *stacks);
void	find_and_push_best_value(t_stacks *stacks);
int		calculate_move_cost(t_stack *stack, int position);
void	move_to_top_b_opt(t_stacks *stacks, int position);
void	push_multiple_chunks(t_stacks *stacks, int *sorted_vals,
		int chunk_size, int chunk_count);
void	push_chunk_optimized(t_stacks *stacks, int max_threshold,
		int min_threshold);

// Optimized sorting functions
void	sort_three_elements_opt(t_stacks *stacks);
void	sort_six_or_less_opt(t_stacks *stacks);
void	push_smallest_to_b_opt(t_stacks *stacks);
int		*get_sorted_array(t_stack *stack);
int		*create_array_from_stack(t_stack *stack);
void	bubble_sort_array(int *array, int size);
int		push_range_to_b(t_stacks *stacks, int min_val, int max_val);

int		is_sorted(t_stack *stack);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		get_position(t_stack *stack, int value);

// Command optimization functions
void	add_command(t_stacks *stacks, char *cmd);
void	optimize_commands(t_stacks *stacks);
void	print_commands(t_stacks *stacks);
void	free_commands(t_command *commands);
t_command	*create_command(char *cmd);
void	merge_operations(t_stacks *stacks);
int		merge_swap_operations(t_command *current);
int		merge_rotate_operations(t_command *current);
int		merge_reverse_rotate_operations(t_command *current);
void	remove_opposite_operations(t_stacks *stacks);
int		check_and_remove_push_ops(t_stacks *stacks, t_command *current);
int		check_and_remove_rotate_ops(t_stacks *stacks, t_command *current);
int		check_ra_rra_pair(t_command *current, t_command *next);
int		check_rb_rrb_pair(t_command *current, t_command *next);
void	remove_next_command(t_command *current);
void	remove_current_and_next(t_command **head, t_command *current);
void	find_and_update_prev_link(t_command **head, t_command *current,
		t_command *to_remove2);
void	merge_consecutive_operations(t_stacks *stacks);
void	remove_command_from_list(t_command **head, t_command *to_remove);

// Modified operation functions
void	sa_opt(t_stacks *stacks);
void	sb_opt(t_stacks *stacks);
void	ss_opt(t_stacks *stacks);
void	pa_opt(t_stacks *stacks);
void	pb_opt(t_stacks *stacks);
void	ra_opt(t_stacks *stacks);
void	rb_opt(t_stacks *stacks);
void	rr_opt(t_stacks *stacks);
void	rra_opt(t_stacks *stacks);
void	rrb_opt(t_stacks *stacks);
void	rrr_opt(t_stacks *stacks);

#endif 