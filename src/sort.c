/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:24:49 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/23 08:50:20 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int number_len(int number)
{
	int len=!number;
	while (number)
	{
		 len++;
		 number/=10;
	}
	return len;
}

int sort_algo_radix(t_stack *stack_a, t_stack *stack_b, int right_shift)
{
	int	i;
	int	len;
	// int	limit;
	int biggest_number;

	biggest_number = stack_a->numbers[biggest_in_stack(stack_a)];
	if (right_shift > number_len(biggest_number) || is_sorted(stack_a))
	{
		while (stack_b->size > 0)
			push(stack_b, stack_a, 'a');
		return (0);
	}
	i = 0;
	len = stack_a->size;
	while (i < len && !is_sorted(stack_a))
	{
		if (!(stack_a->numbers[i] >> right_shift & 1))
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
		i++;
	}
	i = 0;
	len = stack_b->size;
	while (i < len)
	{
		push(stack_b, stack_a, 'a');
		i++;
	}
	return (sort_algo_radix(stack_a, stack_b, right_shift + 1));
}

/*
This function identifies what type of sort I will use on my stack
*/
void sort(t_stack *stack_a, t_stack *stack_b)
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
