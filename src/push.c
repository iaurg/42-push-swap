/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 07:27:43 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/26 06:36:49 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** @brief action to push from source stack to dest stack
 *  on push we increase dest size/top and decrease source
 *  dest/top. We also print action after operations.
 *  @param *source pointer to source stack
 *  @param *dest pointer to dest stack
 *  @param stack_name letter that represent stack (a,b)
 *  @return void
 */
void	push(t_stack *source, t_stack *dest, char stack_name)
{
	if (source->size < 1)
		return ;
	dest->size++;
	dest->top++;
	dest->numbers[dest->top] = source->numbers[source->top];
	source->numbers[source->top] = 0;
	source->top--;
	source->size--;
	print_action("p", stack_name);
}
