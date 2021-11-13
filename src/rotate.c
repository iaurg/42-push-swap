/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 06:40:13 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/13 17:09:17 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	rotate(t_stack *stack, char stack_name)
{
	int holder;
	int top;
	int i;

	if (stack->size < 2)
		return ;
	top = stack->top;
	holder = stack->numbers[top];
	i = stack->size;
	while (i > 0)
	{
		stack->numbers[i] = stack->numbers[i - 1];
		i--;
	}
	stack->numbers[0] = holder;
	if (stack_name)
		ft_printf("r%c\n", stack_name);
}

void	rr_rotate(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	ft_printf("rrr\n");
}
