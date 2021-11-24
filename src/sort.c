/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:24:49 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/24 07:23:55 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	bin_number_len(int number)
{
	int	count;

	count = 0;
	while ((number >> count) != 0)
		count++;
	return (count);
}

int	count_order_numbers(t_stack *stack)
{
	int	len;
	int	count;

	count = 0;
	len = 0;
	while (len <= stack->size)
	{
		if (stack->numbers[len] == len)
			count++;
		else
			count = 0;
		len++;
	}
	return (count);
}

/*
Hold recursion and send all back to A if is already sorted or shift is greater
Right shift only certain number of bytes
1010 >> 0 = 1010
1010 >> 1 = 101
1010 >> 2 = 10
*/

/** @file sort.c
 * @brief Order stack using radix and right shift binary.
 *
 *  If the character is a newline ('\n'), the cursor should
 *  be moved to the next line (scrolling if necessary).  If
 *  the character is a carriage return ('\r'), the cursor
 *  should be immediately reset to the beginning of the current
 *  line, causing any future output to overwrite any existing
 *  output on the line.  If backsapce ('\b') is encountered,
 *  the previous character should be erased (write a space
 *  over it and move the cursor back one column).  It is up
 *  to you how you want to handle a backspace occurring at the
 *  beginning of a line.
 *
 *  @param ch the character to print
 *  @return Zero after recursion
 */
int	sort_algo_radix(t_stack *stack_a, t_stack *stack_b, int right_shift)
{
	int	i;
	int	limit;
	int	len;

	if (right_shift > bin_number_len(stack_a->size - 1) || is_sorted(stack_a))
	{
		while (stack_b->size > 0)
			push(stack_b, stack_a, 'a');
		return (0);
	}
	i = -1;
	len = stack_a->size;
	limit = count_order_numbers(stack_a);
	while (++i < len - limit && !is_sorted(stack_a))
	{
		if ((stack_a->numbers[stack_a->top] >> right_shift & 1) == 1)
			rotate(stack_a, 'a');
		else
			push(stack_a, stack_b, 'b');
	}
	i = -1;
	len = stack_b->size;
	while (++i < len - limit)
		push(stack_b, stack_a, 'a');
	return (sort_algo_radix(stack_a, stack_b, right_shift + 1));
}

/*
This function identifies what type of sort I will use on my stack
*/
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 3)
		while (!is_sorted(stack_a))
			swap(stack_a, 'a');
	else if (stack_a->size == 3)
		while (!is_sorted(stack_a))
			size_3(stack_a);
	else if (stack_a->size <= 5)
		while (!is_sorted(stack_a))
			size_5(stack_a, stack_b);
	else
		sort_algo_radix(stack_a, stack_b, 0);
}
