/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:02:53 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/09/08 09:15:25 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*prev;
	int				nbr;
	struct s_node	*next;
}	t_node;

typedef struct s_var
{
	unsigned int	size_a;
	unsigned int	size_b;
	unsigned int	original_size;
	unsigned int	ops;
	unsigned int	lower_bound;
	unsigned int	upper_bound;
	unsigned int	quantile;
	unsigned int	moves_min;
	unsigned int	moves_max;
	unsigned int	mod_min;
	unsigned int	mod_max;
	unsigned int	size_in;

	int				*sorted_array;
	int				median;
	int				min;
	int				max;
}	t_var;

int	ft_rotate(t_node **stack, int reverse, char *a_or_b);
int	ft_swap(t_node **stack, char *a_or_b);
int	ft_push(t_node **stack_in, t_node **stack_out, t_var *master, char *a_or_b);
int	push_swap(t_var *master, int *initial_array);

unsigned int	hundred_args(t_node **stack_a, t_node **stack_b, unsigned int *size_a, int *sorted_array, unsigned int *ops);
unsigned int	five_args(t_node **stack_a, t_node **stack_b, unsigned int *size_a, int *sorted_array, unsigned int *ops);
void			three_args(t_node **stack, unsigned int size_stack, unsigned int size_other,  int *sorted_array, unsigned int *ops); 

void			sort_and_push(t_node **stack_b, t_node **stack_a, unsigned int *size_b, unsigned int *size_a, unsigned int *ops);
void			find_moves(int min, int max, unsigned int *size, unsigned int *ops, t_node **stack);
void			adjust_moves(unsigned int *moves_min, unsigned int *moves_max, unsigned int *size, unsigned int *ops, t_node **stack);
unsigned int	smart_rotate(unsigned int *moves_min, unsigned int *moves_max, int mod_min, int mod_max, t_node **stack);
int				find_median(unsigned int size, t_node *stack);

int		find_min_max(t_node *stack, int min_or_max, unsigned int size);
int		is_it_in_array(int nbr, int *sorted_array, unsigned int start_index, unsigned int end_index);
int		is_it_ordered(t_node *stack, unsigned int size, int *sorted_array, unsigned int index);
t_node	*array_to_list(int *initial_array, unsigned int size);
int		*sort_array(int *stack, unsigned int size);

#endif
