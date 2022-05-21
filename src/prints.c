/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:00:10 by itaureli          #+#    #+#             */
/*   Updated: 2022/05/21 18:02:53 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** @brief print error based on pdf
 *  @param void
 *  @return int false (0)
 */
int print_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (false);
}

/** @brief print action (pa, pb, sa...)
 *  @param char* string of letters that represent action (p,s,r, rr...)
 *  @param stack_name letter that represent stack (a,b)
 *  @return void
 */
void print_action(char *type, char stack_name)
{
	ft_putstr_fd(type, STDOUT_FILENO);
	ft_putchar_fd(stack_name, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
