/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 01:27:36 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/08 12:25:57 by mkazuhik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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