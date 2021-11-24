/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 08:37:44 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/24 08:01:19 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	size_3(t_stack *stack)
{
	int	top;
	int	middle;
	int	bottom;

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

void	size_5(t_stack *stack_a, t_stack *stack_b)
{
	int	smallest;

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
	push(stack_b, stack_a, 'a');
	if (stack_b->size >= 1)
		push(stack_b, stack_a, 'a');
}
