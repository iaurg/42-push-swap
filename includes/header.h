/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:34:06 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/13 17:07:31 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdbool.h>
# include "../libs/libft/libft.h"

typedef struct s_stack
{
	int		*numbers;
	int		size;
	int		top;
	char	stack_name;
}	t_stack;

int			print_error(void);
int			is_valid(char **argv);
void		init_stack(t_stack *stack, char **values);
t_stack		*alloc_stack(int argc, int start_size);
void		parse_stack_a(t_stack *stack, char **argv, int size);
int			is_sorted(t_stack *stack);
void		swap(t_stack *stack, char stack_name);
void		ss_swap(t_stack *stack_a, t_stack *stack_b);
void		push(t_stack *source, t_stack *dest, char stack_name);
void		rotate(t_stack *stack, char stack_name);
void		rr_rotate(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate(t_stack *stack, char stack_name);
void		rr_reverse_rotate(t_stack *stack_a, t_stack *stack_b);
void		size_3(t_stack *stack);
void		size_5(t_stack *stack_a, t_stack *stack_b);
int			smallest_in_stack(t_stack *stack);
void		move_nbr_top(t_stack *stack, int index, char stack_name);
void		bad_sort_numbers(t_stack *stack_a, t_stack *stack_b);
void		sort_array(t_stack *stack);
void		sort_algo(t_stack *stack_a, t_stack *stack_b, t_stack *stack_aux);
int			binary_search(t_stack *stack, int nbt_to_find);
#endif
