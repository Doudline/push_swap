/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:02:53 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/10/06 10:48:44 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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
	unsigned int	moves_min;
	unsigned int	moves_max;
	unsigned int	moves_beg;
	unsigned int	moves_end;
	unsigned int	mod_min;
	unsigned int	mod_max;
	unsigned int	size_in;

	int				*sorted_array;
	int				median;
	int				min;
	int				max;
	int				lower_bound;
	int				upper_bound;
	int				quantile;
}	t_var;

int	int_limit(int argc, char **argv);
int	non_integer(int argc, char **argv);
int	duplicates(int argc, int *initial_array);
int	*create_initial_array(int argc, char **argv);
long long	ft_atoi(const char *str);

int	is_split_needed(char const *argv);
char **ft_split(char const *s, char sep, int *argc);
static int	ft_count_words(char const *s, char sep);

void	solve_five_hundred(t_node **stack_a, t_node **stack_b, t_var *master);
void	solve_hundred(t_node **stack_a, t_node **stack_b, t_var *master);
void	moves_pusher(t_node **stack_a, t_node **stack_b, t_var *master);
int		moves_from_beginning(t_node *stack, t_var *master);
int		moves_from_end(t_node *stack, t_var *master);

int		ft_rotate(t_node **stack, int reverse, char *a_or_b);
int		ft_swap(t_node **stack, char *a_or_b);
int		ft_push(t_node **stack_in, t_node **stack_out, t_var *master, char *a_or_b);
void	ft_push_size(t_var *master, char *a_or_b);

int		push_swap(t_var *master, int *initial_array);

void	hundred_args(t_node **stack_a, t_node **stack_b, t_var *master);
void	five_args(t_node **stack_a, t_node **stack_b, t_var *master); 
void	three_args(t_node **stack, t_var *master, char *a_or_b);

void			sort_and_push(t_node **stack_b, t_node **stack_a, t_var *master); 
void			find_moves(t_var *master, t_node **stack_b);
void			adjust_moves(t_var *master, t_node **stack_b);
unsigned int	smart_rotate(t_var *master, t_node **stack_b);
int				find_median(unsigned int size, t_node *stack);

int					find_min_max(t_node *stack, int min_or_max, unsigned int size);
int					is_it_in_array(int nbr, int *sorted_array, unsigned int start_index, unsigned int end_index);
int					is_it_ordered(t_node *stack, t_var *master, unsigned int size, unsigned int index);
t_node				*array_to_list(int *initial_array, unsigned int size);
int					*sort_array(int *stack, unsigned int size);

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);

#endif
