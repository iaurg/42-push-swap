/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:24:49 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/17 22:10:43 by itaureli         ###   ########.fr       */
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

void	prepare_a(t_stack *stack_a, t_stack *stack_b, int max, int min)
{
	int moves;

	moves = stack_a->size + 1;
	while (moves)
	{
		if (stack_a->numbers[stack_a->top] == max
			|| stack_a->numbers[stack_a->top] == min)
			rotate(stack_a,'a');
		else
			push(stack_a, stack_b, 'a');
		moves--;
	}
}

void	sort_algo(t_stack *stack_a, t_stack *stack_b, t_stack *stack_aux)
{
	int max_number;
	int min_number;

	max_number = stack_aux->numbers[stack_aux->size - 1];
	min_number = stack_aux->numbers[0];
	prepare_a(stack_a, stack_b, max_number, min_number);

	print_stack_2(stack_a);
	print_stack_2(stack_b);
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
	sort_algo(stack_a, stack_b, stack_aux);
}
