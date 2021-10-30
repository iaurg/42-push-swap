/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:34:06 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/30 14:41:58 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdbool.h>
# include "../libs/libft/libft.h"

typedef struct s_stack
{
	t_list	*numbers;
	int		size;
	int		top;
	char	stack_name;
}	t_stack;

//t_stack	stack_a(char *value);
// t_stack	stack_b();
int	ft_print_error(void);
int	is_valid(char **argv);
void init_stack(t_stack *stack, char **argv);
t_stack	*alloc_stack(int argc, char stack_name);
#endif
