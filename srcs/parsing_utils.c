/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/04 05:11:10 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers_in_string(char *str)
{
	int	count;
	int	i;
	int	in_number;

	count = 0;
	i = 0;
	in_number = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (!in_number)
			{
				count++;
				in_number = 1;
			}
		}
		else
			in_number = 0;
		i++;
	}
	return (count);
}

char	**parse_single_argument(char *arg, int *new_argc)
{
	char	**split_args;
	int		count;

	count = count_numbers_in_string(arg);
	if (count <= 1)
		return (NULL);
	split_args = ft_split(arg, ' ');
	if (!split_args)
		return (NULL);
	*new_argc = count + 1;
	return (split_args);
}

int	process_single_string_argument(char *arg, char ***parsed_args,
		int *new_argc)
{
	char	**split_args;

	split_args = parse_single_argument(arg, new_argc);
	if (!split_args)
		return (0);
	if (!validate_split_arguments(split_args))
	{
		free_split_args(split_args);
		return (0);
	}
	*parsed_args = split_args;
	return (1);
}
