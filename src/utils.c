/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:56:01 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/07 13:00:49 by itaureli         ###   ########.fr       */
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

// Try bubble
void	sort_array(t_stack *stack)
{
	int	step;
	int	left_temp;
	int size;
	int swapped;

	swapped = 1;
	size = stack->size - 1;
	step = 0;
	while (swapped)
	{
		while (step < size - 1)
		{
			if (stack->numbers[step] > stack->numbers[step + 1])
			{
				left_temp = stack->numbers[step];
				stack->numbers[step] = stack->numbers[step + 1];
				stack->numbers[step + 1] = left_temp;
			}
			step++;
		}
		step = 0;
		size--;
	}
}
