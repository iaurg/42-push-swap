/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:06:34 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/30 14:09:27 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
OK: Validate it's a integer with INT_MAX and INT_MIN
OK: Not allow duplicates
TODO: Review pdf rules
OK: Not allow strings
*/

// Remove it
#include <stdio.h>

static int	is_valid_number(char **argv)
{
	int i;
	int j;
	long value;

	j = 0;
	i = 1;
	while (argv[i])
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

static int has_duplicate(char **argv)
{
	int i;
	int j;

	i = 1;
	j = 2;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (true);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (false);
}

int is_valid(char **argv)
{
	if(!is_valid_number(argv) || has_duplicate(argv))
		return (false);
	return(true);
}
