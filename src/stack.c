/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 06:42:12 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/13 17:11:04 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	parse_stack_a(t_stack *stack, char **argv, int size)
{
	int i;
	int j;

	i = 0;
	j = size;

	while (i < j)
	{
		stack->numbers[i] = ft_atoi(argv[j - i]);
		stack->top++;
		i++;
	}
}

t_stack	*alloc_stack(int size, int start_size)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = -1;
	stack->size = size;
	stack->numbers = malloc(sizeof(int) * start_size);
	if (!stack->numbers)
		return (NULL);
	return (stack);
}
