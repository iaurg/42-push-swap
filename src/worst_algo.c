/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worst_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:40:16 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/07 10:37:40 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Not use this, only testing to see if I can sort properly

#include "../includes/header.h"

void	bad_sort_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int smallest;
	while(stack_a->size)
	{
		smallest = smallest_in_stack(stack_a);
		move_nbr_top(stack_a, smallest, 'a');
		push(stack_a, stack_b, 'b');
	}
	while (stack_b->size)
		push(stack_b, stack_a, 'a');
}
