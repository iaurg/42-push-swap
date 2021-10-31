/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:05:06 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/31 15:14:14 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).
ss : sa and sb at the same time.
*/

void	swap(t_stack *stack)
{
	int holder;

	if (stack->size > 1)
	{
		holder = stack->numbers[0];
		stack->numbers[0] = stack->numbers[1];
		stack->numbers[1] = holder;
	}
}
