/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:24:49 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/11 22:12:13 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

//erase it


void print_stack_2(t_stack *stack)
{

	int i = stack->size - 1;
	while(i >= 0)
	{
		ft_printf("%d\n", stack->numbers[i]);
		i--;
	}
	ft_printf("------\n");
}

void	split_chunk(t_stack *stack_a, t_stack *stack_b, int mid_number)
{

	while (stack_a->numbers[stack_a->top] < mid_number)
	{
		//ft_printf("while1");
		push(stack_a, stack_b, 'b');
	}
	while (stack_a->numbers[0] > mid_number)
	{
		//ft_printf("while2");
		rotate(stack_a, 'a');
		if (stack_a->numbers[stack_a->top] < mid_number)
			push(stack_a, stack_b, 'b');
	}
	while (stack_a->numbers[0] < mid_number)
	{
		//ft_printf("while3");
		reverse_rotate(stack_a, 'a');
		if (stack_a->size > 3)
			push(stack_a, stack_b, 'b');
	}
	return ;
}

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
	//ft_printf("mid_number: %d \n", mid_number);
	while (middle != (last - 2))
	{
		ft_printf("middle: %d, last: %d, midbnr: %d \n", middle, last, mid_number);
		middle = (middle + last)/2;
		if ((middle - last) > 4)
			mid_number = stack_aux->numbers[middle];
		split_chunk(stack_a, stack_b, mid_number);
	}
	//ft_printf("new middle: %d\n", stack_aux->numbers[middle]);
}
