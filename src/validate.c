/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:06:34 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/25 20:12:12 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"



/*
OK: Validate it's a integer with INT_MAX and INT_MIN
TODO: Not allow duplicates
TODO: Review pdf rules
*/

// Remove it
#include <stdio.h>

int	is_valid_number(int argc, char **argv)
{
	int i;
	long value;

	i = 1;
	while (i < argc)
	{
		value = ft_atol(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
			return (false);
		printf("value:%ld\n", value);
		i++;
	}
	return (true);
}
