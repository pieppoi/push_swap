/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 01:27:36 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/08 12:25:57 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
		return (0);
	init_stack(&a, &b, count_word(argv));
	read_arg(argc, argv, &a, &b);
	if (is_sorted(&a))
	{
		free(a.stack);
		free(b.stack);
		return (0);
	}
	else if (a.size < 4)
		sort_three(&a);
	else
		sort_big(&a, &b);
	free(a.stack);
	free(b.stack);
	return (0);
}

void	init_stack(t_stack *a, t_stack *b, int size)
{
	a->stack = malloc(size * sizeof(int));
	if (!a->stack)
		err_exit();
	a->size = 0;
	a->max = INT_MIN;
	a->min = INT_MAX;
	b->stack = malloc(size * sizeof(int));
	if (!b->stack)
	{
		free(a->stack);
		err_exit();
	}
	b->size = 0;
	b->max = INT_MIN;
	b->min = INT_MAX;
}

void	process_split_words(char **nbs, t_stack *a, t_stack *b)
{
	int	index;

	index = 0;
	while (nbs[index])
	{
		if (add_to_stack(a, nbs[index]) == -1)
		{
			all_free(nbs);
			free(a->stack);
			free(b->stack);
			err_exit();
		}
		index++;
		a->size++;
	}
}

void	read_arg(int argc, char **argv, t_stack *a, t_stack *b)
{
	int		i;
	char	**nbs;

	i = 1;
	while (i < argc)
	{
		nbs = ft_split(argv[i], ' ');
		if (!nbs)
		{
			free(a->stack);
			free(b->stack);
			err_exit();
		}
		process_split_words(nbs, a, b);
		all_free(nbs);
		i++;
	}
}

int	add_to_stack(t_stack *a, char *word)
{
	long	value;

	if (!is_digit_str(word))
		return (-1);
	value = ps_atoi(word);
	if (value == LONG_MAX)
		return (-1);
	a->stack[a->size] = (int)value;
	if (!is_unique(a))
		return (-1);
	if (a->max < a->stack[a->size])
		a->max = a->stack[a->size];
	if (a->min > a->stack[a->size])
		a->min = a->stack[a->size];
	return (0);
}

void	err_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
