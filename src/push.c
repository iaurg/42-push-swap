/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:55:28 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/31 16:39:21 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty

pb: push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
*/

#include "../includes/header.h"

static void left_shift(t_stack *stack)
{
	int i;

	i = 1;
	while (i < stack->used_size)
	{
		stack->numbers[i-1] = stack->numbers[i];
		i++;
	}
}

static void right_shift(t_stack *stack, int value)
{
	int i;

	i = stack->used_size;
	while (i >= 0)
	{
		stack->numbers[i+1] = stack->numbers[i];
		i--;
	}
	stack->numbers[0] = value;
}

void	push(t_stack *stack_src, t_stack *stack_dst)
{
	stack_dst->used_size++;
	right_shift(stack_dst, stack_src->numbers[0]);
	left_shift(stack_src);
	stack_src->used_size--;
}
