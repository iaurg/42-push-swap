/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 06:42:12 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/26 06:48:39 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** @brief convert string comming form argv into
 *  numbers and add to array numbers on stack
 *  @param *stack pointer to stack
 *  @param **argv array of strings
 *  @return void
 */
void	parse_stack(t_stack *stack, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = stack->size;
	while (i < j)
	{
		stack->numbers[i] = ft_atoi(argv[j - i]);
		stack->top++;
		i++;
	}
}

/** @brief create a stock pointer based on size,
 *  we use start_size to avoid leaks on iteration
 *  @param int size of stack
 *  @param start_size initial size of stack
 *  @return void
 */
t_stack	*alloc_stack(int size, int start_size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = -1;
	stack->size = size;
	stack->numbers = malloc(sizeof(int) * start_size);
	if (!stack->numbers)
		return (NULL);
	return (stack);
}
