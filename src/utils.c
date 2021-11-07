/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:56:01 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/07 08:20:20 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int is_sorted(t_stack *stack)
{
	int i;

	i = 1;
	if(stack->size == 1 || stack->size == 0)
		return (true);
	while (i < stack->size)
	{
		if (stack->numbers[i - 1] < stack->numbers[i])
			return (false);
		i++;
	}
	return (true);
}

int	smallest_in_stack(t_stack *stack)
{
	int i;
	int smallest_index;

	i = 0;
	smallest_index = 0;
	while (i < stack->size)
	{
		if (stack->numbers[smallest_index] > stack->numbers[i])
			smallest_index = i;
		i++;
	}
	return smallest_index;
}

void	move_nbr_top(t_stack *stack, int index, char stack_name)
{
	if (index > (stack->size / 2))
	{
		while (stack->size - index > 0)
		{
			// ft_printf("size: %d, index: %d \n", stack->size, index);
			if (index == (stack->size - 1))
				return ;
			rotate(stack, stack_name);
			index++;
		}
	}
	else {
		while (index >= 0)
		{
			reverse_rotate(stack, stack_name);
			index--;
		}
	}
}
