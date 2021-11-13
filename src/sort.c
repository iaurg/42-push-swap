/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:24:49 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/13 19:13:37 by itaureli         ###   ########.fr       */
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

	while (stack_a->numbers[stack_a->top] < mid_number && stack_a->size > 2)
	{
		// ft_printf("while1");
		// ft_printf("AS: %d, BS: %d", stack_a->size, stack_b->size);
		push(stack_a, stack_b, 'b');
	}
	while (stack_a->numbers[0] > mid_number)
	{
		//ft_printf("while2, mid:%d, a:%d \n", mid_number, stack_a->size);
		//print_stack_2(stack_a);
		if(stack_a->size == 2)
			break ;
		rotate(stack_a, 'a');
		if (stack_a->numbers[stack_a->top] < mid_number)
		{
			push(stack_a, stack_b, 'b');
		}
	}
	while (stack_a->numbers[0] < mid_number)
	{
		// ft_printf("while3 \n");
		if (stack_a->size > 2)
		{
			reverse_rotate(stack_a, 'a');
			push(stack_a, stack_b, 'b');
		}
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
	middle = (first + last) / 2;
	mid_number = stack_aux->numbers[middle];

	while (middle < (last - 1))
	{
		ft_printf("mid_number: %d \n", mid_number);

		if (last - middle == 3)
		// [11,12,13]
		{
			// ft_printf("if1 \n");
			middle = (middle + last)/2;
			mid_number = stack_aux->numbers[middle];
			split_chunk(stack_a, stack_b, mid_number);
		}
		else if (last - middle > 3)
		{
			// ft_printf("if2 \n");
			middle = (middle + last)/2;
			mid_number = stack_aux->numbers[middle];
			split_chunk(stack_a, stack_b, mid_number);
		}
		else
			break;
		ft_printf("B: \n");
		print_stack_2(stack_b);
	}
}
