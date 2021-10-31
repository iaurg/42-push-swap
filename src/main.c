/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:29:53 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/31 16:33:37 by itaureli         ###   ########.fr       */
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
//REMOVE IT
#include <stdio.h>

static void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int i = 0;
	int j = 0;
	// Test printing stacks
	printf("A\n");
	while (stack_a->used_size > i)
	{
		printf("%d\n", stack_a->numbers[i]);
		i++;
	}
	printf("--------------\n");
	printf("B\n");
	while (stack_b->used_size > j)
	{
		printf("%d\n", stack_b->numbers[j]);
		j++;
	}
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return ft_print_error();
	if (!is_valid(argv))
		return ft_print_error();
	stack_a = alloc_stack(argc - 1, 'a');
	stack_b = alloc_stack(argc - 1, 'b');
	init_stack(stack_a, argv);

	print_stacks(stack_a, stack_b);
	if (is_sorted(stack_a))
		printf("its ordered\n");

	// swap(stack_a);
	push(stack_a, stack_b);
	printf("\n\n");
	print_stacks(stack_a, stack_b);

	push(stack_b, stack_a);
	printf("\n\n");
	print_stacks(stack_a, stack_b);

	// printf("TOP value: %d", stack_a->numbers[stack_a->top]);
	return (0);
}
