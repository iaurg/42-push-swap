/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:34:06 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/31 15:28:07 by itaureli         ###   ########.fr       */
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
	int		used_size;
	char	stack_name;
}	t_stack;

int			ft_print_error(void);
int			is_valid(char **argv);
void		init_stack(t_stack *stack, char **values);
t_stack		*alloc_stack(int argc, char stack_name);
void		push(t_stack *stack_src, t_stack *stack_dst);
int			is_sorted(t_stack *stack);
void		swap(t_stack *stack);
#endif
