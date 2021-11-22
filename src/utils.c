/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:56:01 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/22 20:27:18 by itaureli         ###   ########.fr       */
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
	int size;

	size = stack->size;
	if (index > (size / 2))
	{
		while (size - index > 0)
		{
			if (index == (size - 1))
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

// Try bubble sort while swap
void	sort_array(t_stack *stack)
{
	int	step;
	int	left_temp;
	int size;
	int swapped;

	swapped = 1;
	size = stack->size - 1;
	while (swapped)
	{
		step = 0;
		swapped = 0;
		while (step < size)
		{
			if (stack->numbers[step] > stack->numbers[step + 1])
			{
				left_temp = stack->numbers[step];
				stack->numbers[step] = stack->numbers[step + 1];
				stack->numbers[step + 1] = left_temp;
				swapped = 1;
			}
			step++;
		}
	}
}

/*
Get a number and a stack and return index of this number on stack
*/
int	get_index(t_stack *stack, int nbr)
{
	int index;
	int found_index;
	index = stack->size - 1;
	found_index = 0;
	while (index >= 0)
	{
		if (stack->numbers[index] == nbr)
		{
			found_index = index;
			break;
		}
		index--;
	}
	return found_index;
}

void	normalize_stack(t_stack *stack, t_stack *stack_aux)
{
	int i;
	int j;
	i = 0;
	j = 0;

	while (i <= stack->size - 1)
	{
		while (j <= stack_aux->size - 1)
		{
			if (stack->numbers[i] == stack_aux->numbers[j])
			{
				stack->numbers[i] = j;
				break;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
