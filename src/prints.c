/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:00:10 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/24 07:06:28 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	print_error(void)
{
	ft_putstr_fd("Error \n", 2);
	return (false);
}

void	print_action(char *type, char stack_name)
{
	ft_putstr_fd(type, 2);
	ft_putchar_fd(stack_name, 2);
	ft_putchar_fd('\n', 2);
}
