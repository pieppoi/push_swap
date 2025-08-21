/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 01:28:14 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/08 12:25:57 by mkazuhik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ps_atoi(const char *str)
{
	long	value;
	int		sign;

	sign = 1;
	value = 0;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '-')
		sign = -1;
	while (*str)
	{
		value = value * 10 + *str - '0';
		if ((sign == 1 && value > INT_MAX)
			|| (sign == -1 && value > (long)INT_MAX + 1))
			return (LONG_MAX);
		str++;
	}
	return (value * sign);
}

bool	is_digit_str(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

int	count_word(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				count++;
			j++;
		}
		i++;
		count++;
	}
	return (count);
}

void	all_free(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

bool	is_unique(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->stack[i] == a->stack[a->size])
			return (false);
		i++;
	}
	return (true);
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

void	err_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
