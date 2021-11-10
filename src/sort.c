/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:24:49 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/10 06:48:22 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	sort_algo(t_stack *stack_a, t_stack *stack_b, t_stack *stack_aux)
{
	int mid_number;
	int first;
	int last;
	int middle;

	first = 0;
	last = stack_aux->size - 1;
	middle = (first + last) / 2;
	mid_number = stack_aux->numbers[middle];

	while (stack_a->numbers[stack_a->top] < mid_number)
		push(stack_a, stack_b, 'b');
	while (stack_a->numbers[0] >= mid_number)
	{
		rotate(stack_a, 'a');
		if (stack_a->numbers[stack_a->top] < mid_number)
			push(stack_a, stack_b, 'b');
	}
	while (stack_a->numbers[0] < mid_number)
	{
		reverse_rotate(stack_a, 'a');
		push(stack_a, stack_b, 'b');
	}
	middle = ((middle + last + 1)/2);
	ft_printf("new middle: %d\n", stack_aux->numbers[middle]);
}
