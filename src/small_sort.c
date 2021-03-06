/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 08:37:44 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/26 06:42:14 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** @brief small short hard coded to sort 3 numbers
 *  on stack
 *  @param *stack pointer to stack
 *  @return void
 */
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

/** @brief small short hard coded to sort 4,5 numbers
 *  on stack
 *  @param *stack_a pointer to stack_a
 *  @param *stack_b pointer to stack_b
 *  @return void
 */
void	small_sort(t_stack *stack_a, t_stack *stack_b)
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
