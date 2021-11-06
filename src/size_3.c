/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 08:37:44 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/06 08:59:58 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	size_3(t_stack *stack)
{
	int top;
	int middle;
	int bottom;

	top = stack->numbers[stack->top];
	bottom = stack->numbers[0];
	middle = stack->numbers[1];

	if (top > middle && top < bottom)
		swap(stack, 'a');
	else if (top > middle && middle > bottom)
	{
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
	else if (top > bottom && middle < bottom)
		rotate(stack, 'a');
	else if (top < bottom && middle > bottom)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (top < middle && middle > bottom)
		reverse_rotate(stack, 'a');
}
