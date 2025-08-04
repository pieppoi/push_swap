/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/04 05:11:10 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(int sign, long num)
{
	if (sign == 1 && num > INT_MAX)
		return (1);
	if (sign == -1 && num > (long)INT_MAX + 1)
		return (1);
	return (0);
}

int	parse_sign_and_skip(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

int	is_valid_integer_range(const char *str)
{
	int		sign;
	long	num;
	int		i;

	i = 0;
	num = 0;
	sign = parse_sign_and_skip(str, &i);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i] - '0');
		if (check_overflow(sign, num))
			return (0);
		i++;
	}
	return (1);
}

int	validate_single_arg(char *arg)
{
	int	j;

	j = 0;
	if (arg[j] == '\0')
		return (0);
	if (arg[j] == '+' || arg[j] == '-')
		j++;
	if (arg[j] == '\0')
		return (0);
	while (arg[j])
	{
		if (arg[j] < '0' || arg[j] > '9')
			return (0);
		j++;
	}
	if (!is_valid_integer_range(arg))
		return (0);
	return (1);
}

int	validate_split_arguments(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
	{
		if (!validate_single_arg(split_args[i]))
			return (0);
		i++;
	}
	return (1);
}
