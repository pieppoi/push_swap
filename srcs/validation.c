/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:00 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/04 05:11:10 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_input(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!validate_single_arg(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_input_with_parsing(int argc, char **argv, char ***parsed_args,
		int *new_argc)
{
	*parsed_args = NULL;
	*new_argc = argc;
	if (argc == 2 && ft_strchr(argv[1], ' '))
		return (process_single_string_argument(argv[1], parsed_args, new_argc));
	else
		return (validate_input(argc, argv));
}
