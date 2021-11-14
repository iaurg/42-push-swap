/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:24:49 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/14 20:21:36 by itaureli         ###   ########.fr       */
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
	int x;

	x = stack_a->size + 1;
	while(x >= 0 && !is_sorted(stack_a))
	{
		if (stack_a->numbers[stack_a->top] < mid_number)
			push(stack_a, stack_b, 'b');
		if (stack_a->numbers[stack_a->top] >= mid_number)
			rotate(stack_a, 'a');
		if (stack_a->numbers[0] < mid_number)
			reverse_rotate(stack_a, 'a');
		x--;
	}
}

/*
Need to review this logic

What I need to do after filter all these number on stack B?
I need some sorting after sending to B?

I'm moving something wrong order to be, review post
*/

void	sort_algo(t_stack *stack_a, t_stack *stack_b, t_stack *stack_aux)
{
	int mid_number;
	int first;
	int last;
	int middle;

	first = 0;
	last = stack_aux->size;
	middle = 0;
	while (middle < (last - 1) && !is_sorted(stack_a))
	{
		middle = (middle + last)/2;
		mid_number = stack_aux->numbers[middle];
		ft_printf("mid_number: %d \n", mid_number);
		split_chunk(stack_a, stack_b, mid_number);
	}
}
