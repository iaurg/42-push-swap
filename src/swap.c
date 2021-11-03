/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 07:15:12 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/03 06:52:24 by itaureli         ###   ########.fr       */
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
	ft_printf("s%c\n", stack_name);
}
