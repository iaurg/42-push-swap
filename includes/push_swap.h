/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 07:56:39 by itaureli          #+#    #+#             */
/*   Updated: 2022/05/21 13:15:51 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <limits.h>
#include <stdbool.h>
#include "../libs/libft/libft.h"

/* Standard file descriptors.  */
#define STDIN_FILENO 0	/* Standard input.  */
#define STDOUT_FILENO 1 /* Standard output.  */
#define STDERR_FILENO 2 /* Standard error output.  */

typedef struct s_stack
{
	int *numbers;
	int size;
	int top;
	char stack_name;
} t_stack;

int print_error(void);
int is_valid(char **argv);
void init_stack(t_stack *stack, char **values);
t_stack *alloc_stack(int argc, int start_size);
void parse_stack(t_stack *stack, char **argv);
int is_sorted(t_stack *stack);
void swap(t_stack *stack, char stack_name);
void ss_swap(t_stack *stack_a, t_stack *stack_b);
void push(t_stack *source, t_stack *dest, char stack_name);
void rotate(t_stack *stack, char stack_name);
void rr_rotate(t_stack *stack_a, t_stack *stack_b);
void reverse_rotate(t_stack *stack, char stack_name);
void rr_reverse_rotate(t_stack *stack_a, t_stack *stack_b);
void size_3(t_stack *stack);
void small_sort(t_stack *stack_a, t_stack *stack_b);
int smallest_in_stack(t_stack *stack);
void move_nbr_top(t_stack *stack, int index, char stack_name);
void sort_array(t_stack *stack);
void sort(t_stack *stack_a, t_stack *stack_b);
void normalize_stack(t_stack *stack, t_stack *stack_aux);
void convert_to_binary(t_stack *stack);
void print_action(char *type, char stack_name);
#endif
