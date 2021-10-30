/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:53:58 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/30 15:00:02 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
void init_stack(t_stack *stack, char **argv)
{
	printf("start stack");
}
*/
t_stack	*alloc_stack(int argc, char stack_name)
{
	t_stack *stack;
	int size;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	size = argc - 1;
	stack->size = size;
	stack->numbers = malloc(sizeof(int) * size);
	stack->stack_name = stack_name;
	stack->top = -1; // empty by comparing TOP == -1
	return (stack);
}
