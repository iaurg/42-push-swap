/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:48:14 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/06 13:47:54 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	size_5(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
		push(stack_a, stack_b, 'b');
	while (!is_sorted(stack_a))
		size_3(stack_a);
	if (is_sorted(stack_b))
		rotate(stack_b, 'b');
	push(stack_b, stack_a, 'a');
	if (stack_a->numbers[0] > stack_a->numbers[1])
	{
		swap(stack_a, 'a');
		push(stack_b, stack_a, 'a');
		return ;
	}
	if (stack_b->size > 1)
	{
		rotate(stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
}
