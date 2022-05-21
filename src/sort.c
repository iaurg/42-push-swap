/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:24:49 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/26 06:41:24 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** @brief Count how many shift we can do
 *  on number passed
 *  @param int number to check
 *  @return int with max shift
 */
int	bin_number_len(int number)
{
	int	count;

	count = 0;
	while ((number >> count) != 0)
		count++;
	return (count);
}

/** @brief Count how many number are sorted on stack
 *  @param stack pointer to stack
 *  @return int with total numbers ordered
 */
int	count_order_numbers(t_stack *stack)
{
	int	len;
	int	count;

	count = 0;
	len = 0;
	while (len <= stack->size - 1)
	{
		if (stack->numbers[len] == len)
			count++;
		else
			count = 0;
		len++;
	}
	return (count);
}

/** @brief Sort stack using radix and right shift binary.
 *  With all numbers on stack being positive we can sort
 *  using rightshift byte, based on number 0 position
 *  we move to stack_b, rotate stack_a, then move everything to stack_a
 *  again, we repeat until rightshift can parse biggest number
 *  on stack_a or stack_a is sorted
 *  @param stack_a pointer to stack_a
 *  @param stack_b pointer to stack_b
 *  @param right_shift numbers of bytes to right shift
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

/** @brief Check which type of sort we will use based on
 *  stack_a size and run it until stack_a is sorted.
 *  @param stack_a pointer to stack_a
 *  @param stack_b pointer to stack_b
 *  @return void
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
			small_sort(stack_a, stack_b);
	else
		sort_algo_radix(stack_a, stack_b, 0);
}
