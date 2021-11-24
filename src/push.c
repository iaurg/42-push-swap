/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 07:27:43 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/24 08:01:19 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
