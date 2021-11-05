/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 07:15:12 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/05 06:26:39 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	swap(t_stack *stack, char stack_name)
{
	int holder;
	int top;

	if (stack->size < 2)
		return ;
	holder = stack->numbers[stack->top];
	top = stack->top;
	stack->numbers[top] = stack->numbers[top - 1];
	stack->numbers[top - 1] = holder;
	if (stack_name)
		ft_printf("s%c\n", stack_name);
}

void	ss_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	ft_printf("ss\n");
}
