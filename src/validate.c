/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:06:34 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/26 06:56:29 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** @brief check if all strings on array are
 *  a number
 *  @param **argv array of string
 *  @return int false(0)/true(1)
 */
static int	is_valid_number(char **argv)
{
	int		i;
	int		j;
	long	value;

	j = 0;
	i = 1;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (false);
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

/** @brief check if has any duplicate of a number
 *  on array
 *  @param **argv array of string
 *  @return int false(0)/true(1)
 */
static int	has_duplicate(char **argv)
{
	int	i;
	int	j;

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

/** @brief check if array of string get via args
 *  has valid numbers, and no duplicates.
 *  @param **argv array of string
 *  @return int false(0)/true(1)
 */
int	is_valid(char **argv)
{
	if (!is_valid_number(argv) || has_duplicate(argv))
		return (false);
	return (true);
}
