/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:53:58 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/31 15:28:00 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	init_stack(t_stack *stack, char **values)
{
	int i;
	int value;

	i = 0;
	while (i < stack->size)
	{
		value = ft_atoi(values[i + 1]);
		stack->numbers[i] = value;
		stack->used_size++;
		i++;
	}
}

t_stack	*alloc_stack(int size, char stack_name)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->used_size = 0;
	stack->size = size;
	stack->numbers = malloc(sizeof(int) * size);
	stack->stack_name = stack_name;
	return (stack);
}
