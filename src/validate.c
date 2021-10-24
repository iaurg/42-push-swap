/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:06:34 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/24 13:36:08 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <stdio.h>


int space_verification(char c)
{
	// Validate spaces and breaklines special
	// || (c >= 9 && c <= 13)
    if (c == 32 || (c >= 9 && c <= 13))
    {
        return (1);
    }
    return (0);
}

int ft_validate_args(int argc, char **argv)
{
	int i;
	int j;

	j = 0;
	i = 1;
	while (i < argc)
	{
		if (space_verification(argv[i][j] + 0))
			i++;
		while(argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j] + 0))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
