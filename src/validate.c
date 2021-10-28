/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:06:34 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/28 19:24:43 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"



/*
OK: Validate it's a integer with INT_MAX and INT_MIN
TODO: Not allow duplicates
TODO: Review pdf rules
TODO: Not allow strings
*/

// Remove it
#include <stdio.h>

int	is_valid_number(int argc, char **argv)
{
	int i;
	int j;
	long value;

	j = 0;
	i = 1;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return false;
			j++;
		}
		j = 0;
		value = ft_atol(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
			return (false);
		i++;
	}
	return (true);
}
