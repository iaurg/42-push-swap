/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 07:15:12 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/26 06:50:05 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** @brief action to swap numbers on stack, after swap
 *  we print s(a,b)
 *  @param *stack pointer to stack
 *  @param stack_name letter that represent stack (a,b)
 *  @return void
 */
void	swap(t_stack *stack, char stack_name)
{
	int	holder;
	int	top;

	if (stack->size < 2)
		return ;
	holder = stack->numbers[stack->top];
	top = stack->top;
	stack->numbers[top] = stack->numbers[top - 1];
	stack->numbers[top - 1] = holder;
	if (stack_name)
		print_action("s", stack_name);
}

/** @brief action to swap numbers on both stacks,
 *  after swap we print ss
 *  @param *stack_a pointer to stack_a
 *  @param *stack_b pointer to stack_b
 *  @return void
 */
void	ss_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	print_action("s", 's');
}
