/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/05 04:45:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stacks *stacks)
{
	int	size;

	size = stacks->stack_a->size;
	if (size <= 3)
		sort_three_or_less(stacks);
	else if (size <= 6)
		sort_six_or_less(stacks);
	else
		sort_seven_or_more(stacks);
}

void	sort_three_or_less(t_stacks *stacks)
{
	int	size;

	size = stacks->stack_a->size;
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two(stacks);
	else if (size == 3)
		sort_three(stacks);
}

void	sort_two(t_stacks *stacks)
{
	if (stacks->stack_a->head->value > stacks->stack_a->head->next->value)
		sa(stacks);
}

void	sort_three(t_stacks *stacks)
{
	int	first, second, third;

	first = stacks->stack_a->head->value;
	second = stacks->stack_a->head->next->value;
	third = stacks->stack_a->head->next->next->value;

	if (first > second && second < third && third > first)
		sa(stacks);
	else if (first > second && second > third)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (first > second && second < third && third < first)
		ra(stacks);
	else if (first < second && second > third && third > first)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (first < second && second > third && third < first)
		rra(stacks);
}

void	sort_six_or_less(t_stacks *stacks)
{
	int	pushed_count;

	pushed_count = 0;
	while (stacks->stack_a->size > 3)
	{
		push_smallest_to_b(stacks);
		pushed_count++;
	}
	sort_three(stacks);
	while (pushed_count > 0)
	{
		pa(stacks);
		pushed_count--;
	}
}

void	push_smallest_to_b(t_stacks *stacks)
{
	int	min_val;
	int	min_pos;
	int	stack_size;

	min_val = get_min(stacks->stack_a);
	min_pos = get_position(stacks->stack_a, min_val);
	stack_size = stacks->stack_a->size;

	if (min_pos <= stack_size / 2)
	{
		while (min_pos > 0)
		{
			ra(stacks);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < stack_size)
		{
			rra(stacks);
			min_pos++;
		}
	}
	pb(stacks);
}

void	sort_seven_or_more(t_stacks *stacks)
{
	// シンプルなクイックソート実装
	// 1. ピボットを選択し、aからbに分割
	quick_sort_a_to_b(stacks, stacks->stack_a->size);
	
	// 2. bからaに戻す（ソート済み）
	while (!is_empty(stacks->stack_b))
	{
		push_largest_to_a(stacks);
	}
}

void	quick_sort_a_to_b(t_stacks *stacks, int size)
{
	int	pivot;
	int	pushed;
	int	rotated;

	if (size <= 1)
		return ;
	
	pivot = get_pivot(stacks->stack_a);
	pushed = 0;
	rotated = 0;
	
	// ピボットより小さい値をbにpush
	while (pushed + rotated < size)
	{
		if (stacks->stack_a->head->value <= pivot)
		{
			pb(stacks);
			pushed++;
		}
		else
		{
			ra(stacks);
			rotated++;
		}
	}
	
	// 回転した分を戻す
	while (rotated > 0)
	{
		rra(stacks);
		rotated--;
	}
	
	// 再帰的にソート
	quick_sort_a_to_b(stacks, size - pushed);
}

void	push_largest_to_a(t_stacks *stacks)
{
	int	max_val;
	int	max_pos;
	int	stack_size;

	if (is_empty(stacks->stack_b))
		return;

	max_val = get_max(stacks->stack_b);
	max_pos = get_position(stacks->stack_b, max_val);
	stack_size = stacks->stack_b->size;

	// 最大値をトップに移動
	if (max_pos <= stack_size / 2)
	{
		while (max_pos > 0)
		{
			rb(stacks);
			max_pos--;
		}
	}
	else
	{
		while (max_pos < stack_size)
		{
			rrb(stacks);
			max_pos++;
		}
	}

	// 最大値をaにpush
	pa(stacks);
} 