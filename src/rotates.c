/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 06:32:28 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/24 08:01:19 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack *stack, char stack_name)
{
	int	holder;
	int	top;
	int	i;

	if (stack->size < 2)
		return ;
	top = stack->top;
	holder = stack->numbers[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->numbers[top] = holder;
	if (stack_name)
		print_action("rr", stack_name);
}

void	rr_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	print_action("rr", 'r');
}

void	rotate(t_stack *stack, char stack_name)
{
	int	holder;
	int	top;
	int	i;

	if (stack->size < 2)
		return ;
	top = stack->top;
	holder = stack->numbers[top];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->numbers[i] = stack->numbers[i - 1];
		i--;
	}
	stack->numbers[0] = holder;
	if (stack_name)
		print_action("r", stack_name);
}

void	rr_rotate(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	print_action("r", 'r');
}
