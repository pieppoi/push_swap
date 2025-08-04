/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/04 05:06:31 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_seven_or_more(t_stacks *stacks)
{
	// 単純だが確実な方法：最小値を順次stack_bに移動
	while (stacks->stack_a->size > 3)
	{
		push_smallest_to_b_opt(stacks);
	}
	
	// 残り3個をソート
	if (stacks->stack_a->size == 3)
		sort_three_elements_opt(stacks);
	
	// stack_bから順番にstack_aに戻す
	while (!is_empty(stacks->stack_b))
	{
		pa_opt(stacks);
	}
}

void	quick_sort_large(t_stacks *stacks, int size)
{
	if (size <= 3)
	{
		if (size == 3)
			sort_three_elements(stacks);
		return ;
	}
	if (size <= 6)
	{
		sort_six_or_less(stacks);
		return ;
	}
	
	// 大きなセットに対してチャンク分割方式を使用
	chunk_sort(stacks, size);
}

void	chunk_sort(t_stacks *stacks, int size)
{
	if (size <= 100)
		small_chunk_sort(stacks, size);
	else
		large_chunk_sort(stacks, size);
}

void	push_two_chunks_to_b(t_stacks *stacks, int pivot1, int pivot2)
{
	int	*sorted_values;
	int	total_size;
	int	threshold1;
	int	threshold2;
	int	i;

	total_size = stacks->stack_a->size;
	sorted_values = get_sorted_array(stacks->stack_a);
	if (!sorted_values)
		return ;

	threshold1 = sorted_values[pivot1];
	threshold2 = sorted_values[pivot2];
	free(sorted_values);

	i = 0;
	while (i < total_size && stacks->stack_a->size > 3)
	{
		if (stacks->stack_a->head->value <= threshold1)
		{
			pb_opt(stacks);
		}
		else if (stacks->stack_a->head->value <= threshold2)
		{
			pb_opt(stacks);
			rb_opt(stacks);
		}
		else
		{
			ra_opt(stacks);
		}
		i++;
	}
}

int	*get_sorted_array(t_stack *stack)
{
	int		*array;

	array = create_array_from_stack(stack);
	if (!array)
		return (NULL);
	bubble_sort_array(array, stack->size);
	return (array);
}

int	*create_array_from_stack(t_stack *stack)
{
	int		*array;
	t_node	*current;
	int		i;

	array = (int *)malloc(sizeof(int) * stack->size);
	if (!array)
		return (NULL);
	current = stack->head;
	i = 0;
	while (i < stack->size)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	return (array);
}

void	bubble_sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	push_range_to_b(t_stacks *stacks, int min_val, int max_val)
{
	int	pushed_count;
	int	rotations;
	int	original_size;

	pushed_count = 0;
	rotations = 0;
	original_size = stacks->stack_a->size;

	while (rotations < original_size && stacks->stack_a->size > 3)
	{
		if (stacks->stack_a->head->value >= min_val 
			&& stacks->stack_a->head->value <= max_val)
		{
			pb(stacks);
			pushed_count++;
			rotations = 0;  // リセット
		}
		else
		{
			ra(stacks);
			rotations++;
		}
	}
	return (pushed_count);
}

void	push_back_sorted(t_stacks *stacks)
{
	while (!is_empty(stacks->stack_b))
	{
		find_and_push_best_value(stacks);
	}
}

void	find_and_push_best_value(t_stacks *stacks)
{
	int	max_val;
	int	best_position;

	max_val = get_max(stacks->stack_b);
	best_position = get_position(stacks->stack_b, max_val);

	// 最大値をトップに移動
	move_to_top_b_opt(stacks, best_position);
	pa_opt(stacks);
}

int	calculate_move_cost(t_stack *stack, int position)
{
	if (position <= stack->size / 2)
		return (position);
	else
		return (stack->size - position);
}

void	move_to_top_b_opt(t_stacks *stacks, int position)
{
	while (position > 0)
	{
		if (position <= stacks->stack_b->size / 2)
		{
			rb_opt(stacks);
			position--;
		}
		else
		{
			rrb_opt(stacks);
			position++;
			if (position >= stacks->stack_b->size)
				position = 0;
		}
	}
}

void	small_chunk_sort(t_stacks *stacks, int size)
{
	int	pivot1;
	int	pivot2;

	pivot1 = size / 3;
	pivot2 = (size * 2) / 3;

	// 2つのピボットを使って3つのチャンクに分割
	push_two_chunks_to_b(stacks, pivot1, pivot2);

	// 残りの要素をソート（最大のチャンク）
	if (stacks->stack_a->size <= 3)
		sort_three_elements_opt(stacks);

	// スタックBから最大値順にスタックAに戻す
	push_back_sorted(stacks);
}

void	large_chunk_sort(t_stacks *stacks, int size)
{
	int	chunk_count;
	int	chunk_size;
	int	*sorted_values;

	// より多くのチャンクに分割（大きなデータセット用）
	chunk_count = size / 50;
	if (chunk_count < 2)
		chunk_count = 2;
	if (chunk_count > 20)
		chunk_count = 20;

	chunk_size = size / chunk_count;

	sorted_values = get_sorted_array(stacks->stack_a);
	if (!sorted_values)
		return ;

	// 複数チャンクを順次プッシュ
	push_multiple_chunks(stacks, sorted_values, chunk_size, chunk_count);
	
	free(sorted_values);

	// 残りの要素をソート
	if (stacks->stack_a->size <= 3)
		sort_three_elements(stacks);

	// スタックBから最大値順にスタックAに戻す
	push_back_sorted(stacks);
}

void	push_multiple_chunks(t_stacks *stacks, int *sorted_vals, int chunk_size, int chunk_count)
{
	int	i;
	int	threshold;

	i = 0;
	while (i < chunk_count && stacks->stack_a->size > 3)
	{
		threshold = sorted_vals[(i + 1) * chunk_size - 1];
		if (i == chunk_count - 1)
			threshold = sorted_vals[stacks->stack_a->size + stacks->stack_b->size - 4];

		push_chunk_optimized(stacks, threshold, sorted_vals[i * chunk_size]);
		i++;
	}
}

void	push_chunk_optimized(t_stacks *stacks, int max_threshold, int min_threshold)
{
	int	rotations;
	int	total_size;

	rotations = 0;
	total_size = stacks->stack_a->size;

	while (rotations < total_size && stacks->stack_a->size > 3)
	{
		if (stacks->stack_a->head->value >= min_threshold 
			&& stacks->stack_a->head->value <= max_threshold)
		{
			pb_opt(stacks);
			rotations = 0;
		}
		else
		{
			ra_opt(stacks);
			rotations++;
		}
	}
}
