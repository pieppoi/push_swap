/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/06 06:26:38 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	int					value;
	struct s_node		*next;
	struct s_node		*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_stacks;

// スタック操作関数
t_stack	*create_stack(void);
t_node	*create_node(int value);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	clear_stack(t_stack *stack);
int		is_empty(t_stack *stack);
int		peek(t_stack *stack);
void	print_stack(t_stack *stack, char name);

// 入力検証関数
int		is_valid_number(char *str);
void	free_array(char **array);
int		check_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);

// 基本操作関数
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

// 入力検証関数
int		validate_input(int argc, char **argv);
int		check_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);

// ソート関数
void	sort_stack(t_stacks *stacks);
void	sort_three_or_less(t_stacks *stacks);
void	sort_six_or_less(t_stacks *stacks);
void	sort_seven_or_more(t_stacks *stacks);

// 3個以下のソート
void	sort_two(t_stacks *stacks);
void	sort_three(t_stacks *stacks);

// 6個以下のソート
void	push_smallest_to_b(t_stacks *stacks);

// 7個以上のソート（クイックソート）
void	quick_sort_a_to_b(t_stacks *stacks, int size);
void	quick_sort_b_to_a(t_stacks *stacks, int size);
void	sort_a_to_b(t_stacks *stacks, int size);
void	push_largest_to_a(t_stacks *stacks);
void	push_largest_to_b(t_stacks *stacks);
int		get_pivot(t_stack *stack);

// ユーティリティ関数
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		get_position(t_stack *stack, int value);
void	error_exit(t_stacks *stacks);

#endif 