/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 06:32:28 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/26 06:40:16 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** @brief action to reverse rotate stack, after rotate
 *  we print rr(a,b)
 *  @param *stack pointer to stack
 *  @param stack_name letter that represent stack (a,b)
 *  @return void
 */
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

/** @brief action to reverse rotate both stacks,
 *  using reverse_rotate, after rotate we print rrr
 *  @param *stack_a pointer to stack_a
 *  @param *stack_b pointer to stack_b
 *  @return void
 */
void	rr_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	print_action("rr", 'r');
}

/** @brief action to rotate stack, after rotate
 *  we print r(a,b)
 *  @param *stack pointer to stack
 *  @param stack_name letter that represent stack (a,b)
 *  @return void
 */
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

/** @brief action to double rotate stacks, after rotate
 *  we print rr
 *  @param *stack_a pointer to stack_a
 *  @param *stack_b pointer to stack_b
 *  @return void
 */
void	rr_rotate(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	print_action("r", 'r');
}
