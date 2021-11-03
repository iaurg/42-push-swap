/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:34:06 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/03 06:48:51 by itaureli         ###   ########.fr       */
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
t_stack		*alloc_stack(int argc);
void		parse_stack_a(t_stack *stack, char **argv, int size);
int			is_sorted(t_stack *stack);
void		swap(t_stack *stack, char stack_name);
void		push(t_stack *source, t_stack *dest);
void		rotate(t_stack *stack, char stack_name);
#endif
