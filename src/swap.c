/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 07:15:12 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/01 07:25:00 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	swap(t_stack *stack, char stack_name)
{
	int holder;

	if (stack->size < 2)
		return ;
	holder = stack->numbers[stack->top];
	stack->numbers[stack->top] = stack->numbers[stack->top - 1];
	stack->numbers[stack->top - 1] = holder;
	if (stack_name)
		ft_putstr_fd("swaped\n", 1);
}
