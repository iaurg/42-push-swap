/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:24:49 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/19 06:38:20 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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
	int moves;

	moves = stack_a->size + 1;
	while(moves >= 0 && !is_sorted(stack_a))
	{
		if (stack_a->numbers[stack_a->top] < mid_number)
			push(stack_a, stack_b, 'b');
		if (stack_a->numbers[stack_a->top] >= mid_number)
			rotate(stack_a, 'a');
		else if (stack_a->numbers[0] < mid_number)
			reverse_rotate(stack_a, 'a');
		moves--;
	}
}

/*
Menor e maior fica no A
Divide os numeros e manda pra B
Get move e get index
get move com base no tamanho da array
Funções auxiliares, maior numero, menor numero, get index, move to top
*/

void	prepare_a(t_stack *stack_a, t_stack *stack_b, int max, int min, int mid)
{
	int moves;

	moves = stack_a->size + 1;
	while (moves)
	{
		if (stack_a->numbers[stack_a->top] == max
			|| stack_a->numbers[stack_a->top] == min)
			rotate(stack_a,'a');
		else if (stack_a->numbers[stack_a->top] <= mid)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a,'a');
		moves--;
	}
	while (!is_sorted(stack_a))
	{
		if (stack_a->numbers[stack_a->top] == max
			|| stack_a->numbers[stack_a->top] == min)
			rotate(stack_a,'a');
		else
			push(stack_a, stack_b, 'b');
	}
}

void send_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int moves;
	int top_b;

	top_b = stack_b->top;
	i = top_b;
	moves = stack_a->size + stack_b->size;

	while (i >= 0)
	{
		if (i >= top_b / 2)
		{

		}
		i--;
	}
}

void iterate_into_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->top >= 0)
		send_to_a(stack_a, stack_b);
}

void	sort_algo(t_stack *stack_a, t_stack *stack_b, t_stack *stack_aux)
{
	int max_number;
	int min_number;
	int mid_number;

	max_number = stack_aux->numbers[stack_aux->size - 1];
	min_number = stack_aux->numbers[0];
	mid_number = stack_aux->numbers[stack_aux->size/2];
	prepare_a(stack_a, stack_b, max_number, min_number, mid_number);
	iterate_into_b(stack_a, stack_b);
}

void sort(t_stack *stack_a, t_stack *stack_b, t_stack *stack_aux)
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
		sort_algo(stack_a, stack_b, stack_aux);
}
