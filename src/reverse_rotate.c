/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 06:32:28 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/05 06:34:47 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	reverse_rotate(t_stack *stack, char stack_name)
{
	int holder;
	int top;
	int i;

	if (stack->size < 2)
		return ;
	top = stack->top;
	holder = stack->numbers[0];
	i = 0;
	while (i < stack->size)
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->numbers[top] = holder;
	if (stack_name)
		ft_printf("rr%c\n", stack_name);
}

void	rr_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	ft_printf("rrr\n");
}
