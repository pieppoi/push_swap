/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 01:28:30 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/08/08 01:28:32 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	max;
	int	min;
}				t_stack;

//main
int		add_to_stack(t_stack *a, char *word);
void	init_stack(t_stack *a, t_stack *b, int size);
void	read_arg(int argc, char **argv, t_stack *a);
void	err_exit(void);

//ope
void	swap_ab(t_stack *stack, char *str);
void	swap_ss(t_stack *a, t_stack *b);
void	push_arg1_to_arg2(t_stack *from, t_stack *to, char *str);
void	rotate_ab(t_stack *stack, char *str);
void	rotate_rr(t_stack *a, t_stack *b);
void	reverse_rotate_ab(t_stack *stack, char *str);
void	reverse_rotate_rrr(t_stack *a, t_stack *b);
void	updata_minmax(t_stack *from, t_stack *to, int nb);

//find
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
int		find_index(t_stack *stack, int nb);
int		find_lcost_nb(t_stack *a, t_stack *b);
int		find_pos_b(t_stack *stack_b, int nb);

//sort
bool	is_sorted(t_stack *stack);
void	sort_three(t_stack *array);
void	sort_big(t_stack *a, t_stack *b);
void	push_a_phase(t_stack *a, t_stack *b);
void	set_stack(t_stack *a, t_stack *b, int a_nb);

//set
void	set_a_head(t_stack *a, int set_nb);
void	set_b_tail(t_stack *b, int set_nb);
void	set_both_rotate(t_stack *a, t_stack *b, int b_nb, int a_nb);

//utils
bool	is_digit_str(char *str);
int		ps_atoi(const char *str);
int		count_word(char **argv);
void	all_free(char **result);
bool	is_unique(t_stack *a);

#endif