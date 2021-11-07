/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:48:14 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/07 08:24:26 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

// Sort stack with 4 or 5 elements
void	size_5(t_stack *stack_a, t_stack *stack_b)
{
	int smallest;

	smallest = smallest_in_stack(stack_a);
	move_nbr_top(stack_a, smallest, 'a');

	if (stack_a->size == 5)
	{
		push(stack_a, stack_b, 'b');
		smallest = smallest_in_stack(stack_a);
		move_nbr_top(stack_a, smallest, 'a');
	}
	while (stack_a->size > 3)
		push(stack_a, stack_b, 'b');
	while (!is_sorted(stack_a))
		size_3(stack_a);
	if (is_sorted(stack_b))
		rotate(stack_b, 'b');
	push(stack_b, stack_a, 'a');
	if (stack_b->size > 1)
	{
		rotate(stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
}
