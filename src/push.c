/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 07:27:43 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/06 13:45:40 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void push(t_stack *source, t_stack *dest, char stack_name)
{
	if (source->size < 1)
		return ;
	dest->size++;
	dest->top++;
	dest->numbers[dest->top] = source->numbers[source->top];
	source->numbers[source->top] = 0;
	source->top--;
	source->size--;
	ft_printf("p%c\n", stack_name);
}
