/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:29:53 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/07 09:43:47 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
OK: Entry file and reader from args
TODO: Validate with norminette
TODO: Validate memory leaks
TODO: Ascending order number 1,2,3,4,5,6,7,8,9,10...
TODO: Instructions must be separaed by a ’\n’ and nothing else.
TODO: The program must display the smallest list of instructions possible to sort the stack
a, the smallest number being at the top.
TODO: The first argument should be at the top of the stack (be careful about the order)


GOAL: The goal is to sort in ascending order numbers into stack A.


You have to write a program named push_swap which will receive as an argument
the stack a formatted as a list of integers. The first argument should be at the top
of the stack (be careful about the order)

A: contains a random number of either positive or negative numbers without
any duplicates.
B: is empty
*/

#include "../includes/header.h"

void print_stack(t_stack *stack)
{

	int i = stack->size - 1;
	while(i >= 0)
	{
		ft_printf("%d\n", stack->numbers[i]);
		i--;
	}
	ft_printf("------\n");
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return print_error();
	if (!is_valid(argv))
		return print_error();
	stack_a = alloc_stack(argc - 1);
	parse_stack_a(stack_a, argv, argc - 1);
	if (is_sorted(stack_a))
		return(0);
	stack_b = alloc_stack((argc - 1) - stack_a->size);

	if (stack_a->size < 3)
		while (!is_sorted(stack_a))
			swap(stack_a, 'a');
	else if (stack_a->size == 3)
		while (!is_sorted(stack_a))
			size_3(stack_a);
	else if (stack_a->size == 4 || stack_a->size == 5)
		while (!is_sorted(stack_a))
			size_5(stack_a, stack_b);
	else
		while (!is_sorted(stack_a))
			bad_sort_numbers(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
