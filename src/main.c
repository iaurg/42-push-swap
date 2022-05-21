/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:29:53 by itaureli          #+#    #+#             */
/*   Updated: 2022/05/21 19:18:46 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_aux;

	if (argc < 2)
		return (0);
	if (!is_valid(argv))
		return (print_error());
	stack_a = alloc_stack(argc - 1, argc - 1);
	parse_stack(stack_a, argv);
	if (is_sorted(stack_a))
		return (0);
	stack_b = alloc_stack((argc - 1) - stack_a->size, argc - 1);
	stack_aux = alloc_stack((argc - 1), argc - 1);
	parse_stack(stack_aux, argv);
	sort_array(stack_aux);
	normalize_stack(stack_a, stack_aux);
	sort(stack_a, stack_b);
	free(stack_a->numbers);
	free(stack_b->numbers);
	free(stack_aux->numbers);
	free(stack_a);
	free(stack_b);
	free(stack_aux);
	return (0);
}
