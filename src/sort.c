/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:24:49 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/08 06:47:52 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	sort_algo(t_stack *stack_a, t_stack *stack_b, t_stack *stack_aux)
{
	int mid;

	mid = stack_aux->numbers[stack_aux->size / 2];
	ft_printf("sort_algo, mid: %d, stackA top: %d sze-1: %d\n", mid, stack_a->numbers[stack_a->top], stack_a->numbers[stack_a->size-1]);
	while (stack_a->numbers[stack_a->top] < mid)
		push(stack_a, stack_b, 'b');
	while (stack_a->numbers[stack_a->size - 1] < mid)
	{
		ft_printf("menor,");
		rotate(stack_a, 'a');
		push(stack_a, stack_b, 'b');
	}
}
