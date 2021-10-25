/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:06:34 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/25 06:28:05 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"



/*
TODO: Validate it's a integer with INT_MAX and INT_MIN
TODO: Not allow duplicates
*/

// Remove it
#include <stdio.h>

static int is_space(char c)
{
	// Validate spaces and breaklines special
	// || (c >= 9 && c <= 13)
    if (c == 32 || (c >= 9 && c <= 13))
    {
        return (true);
    }
    return (false);
}

int	is_valid_number(int argc, char **argv)
{
	int i;
	int j;
	int value;

	j = 0;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (is_space(*argv[i] + 0)){
			i++;
			continue;
		}
		printf("value: %d", value);
		if (!ft_isdigit(value))
			return (false);
		i++;
	}
	return (true);
}
