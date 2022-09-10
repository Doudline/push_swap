/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 08:26:52 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/09/07 11:07:49 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_and_push(t_node **stack_b, t_node **stack_a,  unsigned int *size_b, 
		unsigned int *size_a, unsigned int *ops)
{
	int	min;
	int	max;
	int	i;
	int	median;

	min = 0;
	max = 0;
	median = find_median(*size_b, *stack_b);
	i = *size_b;
	while (*size_b > 0)
	{
		min = find_min_max(*stack_b, 0, *size_b); 
		max = find_min_max(*stack_b, 1, *size_b); 
		printf("%d %d", min, max); 
		find_moves(min, max, size_b, ops, stack_b);
		*ops += ft_push(stack_a, stack_b, size_a, size_b, "a");
		if ((*stack_a)->nbr	<= median)
		{
			*ops += ft_rotate(stack_a, 0, "a");
			i--;
		}
	}
	while (i-- > 0)
		*ops += ft_rotate(stack_a, 0, "a");
}

void	find_moves(int min, int max, unsigned int *size, unsigned int *ops, t_node **stack)
{
	t_node *temp;
	unsigned int	moves_min;
	unsigned int	moves_max;
	
	moves_min = 0;
	moves_max = 0;
	temp = *stack;
	while (temp->nbr != min)
	{
		moves_min++;
		temp = temp->next;

	}
	temp = *stack;
	while (temp->nbr != max)
	{
		moves_max++;
		temp = temp->next;
	}
	adjust_moves(&moves_min, &moves_max, size, ops, stack);
}

void	adjust_moves(unsigned int *moves_min, unsigned int *moves_max, unsigned int *size, unsigned int *ops,
	   	t_node **stack)
{
	int	mod_min;
	int	mod_max;

	mod_min = 0;
	mod_max = 0;
	if (*moves_min > *size / 2)
	{
		*moves_min = *size - *moves_min;
		mod_min++;
	}
	if (*moves_max > *size / 2)
	{
		*moves_max = *size - *moves_max;
		mod_max++;
	}
	*ops += smart_rotate(moves_min, moves_max, mod_min, mod_max, stack);
}

unsigned int	smart_rotate(unsigned int *moves_min, unsigned int *moves_max, int mod_min, int mod_max, t_node **stack)
{
	int	i;

	if (*moves_max > *moves_min)
	{
		i = *moves_min;
		if (mod_min == 1)
		{
			while ((*moves_min)-- > 0)
				ft_rotate(stack, 1, "b");
		}
		while ((*moves_min)-- > 0 && mod_min == 0)
			ft_rotate(stack, 0, "b");
	}
	else
	{
		i = *moves_max;
		if (mod_max == 1)
		{
			while ((*moves_max)-- > 0)
				ft_rotate(stack, 1, "b");
		}
		while ((*moves_max)-- > 0 && mod_max == 0)
		{
			ft_rotate(stack, 0, "b");
		}
	}
	return (i);
}

int	find_median(unsigned int size, t_node *stack)
{
	int	*array;
	int	*sorted_array;
	int	i;


	array = malloc(size * 4);
	i = -1;
	while (++i < size)
	{
		array[i] = stack->nbr;
		stack = stack->next;
	}
	sorted_array = sort_array(array, size);
	free (array);
	array = NULL;
	return (sorted_array[size / 2]);
}
