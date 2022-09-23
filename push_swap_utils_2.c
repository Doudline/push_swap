/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 08:26:52 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/09/23 10:06:24 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_and_push(t_node **stack_b, t_node **stack_a, t_var *master) 
{
	unsigned int	i;
	int				median;
	
	master->min = 0;
	master->max = 0;
	median = find_median(master->size_b, *stack_b);
	i = master->size_b;
	while (master->size_b > 0)
	{
		master->min = find_min_max(*stack_b, 0, master->size_b); 
		master->max = find_min_max(*stack_b, 1, master->size_b); 
		find_moves(master, stack_b);
		master->ops += ft_push(stack_a, stack_b, master, "a");
		if ((*stack_a)->nbr	< median)
		{
			master->ops += ft_rotate(stack_a, 0, "a");
			i--;
		} 
	} 
	while (i-- > 0)
		master->ops += ft_rotate(stack_a, 0, "a");
}

void	find_moves(t_var *master, t_node **stack_b)
{
	t_node *temp;

	master->moves_min = 0;
	master->moves_max = 0;
	temp = *stack_b;
	while (temp->nbr != master->min)
	{
		master->moves_min++;
		temp = temp->next;

	}
	temp = *stack_b;
	while (temp->nbr != master->max)
	{
		master->moves_max++;
		temp = temp->next;
	}
	adjust_moves(master, stack_b);
}

void	adjust_moves(t_var *master, t_node **stack_b)
{
	master->mod_min = 0;
	master->mod_max = 0;
	if (master->moves_min > master->size_b / 2)
	{
		master->moves_min = master->size_b - master->moves_min;
		master->mod_min++;
	}
	if (master->moves_max > master->size_b / 2)
	{
		master->moves_max = master->size_b - master->moves_max;
		master->mod_max++;
	}
	master->ops += smart_rotate(master, stack_b);
}

unsigned int	smart_rotate(t_var *master, t_node **stack_b)
{
	int	i;

	if (master->moves_max > master->moves_min)
	{
		i = master->moves_min;
		if (master->mod_min == 1)
		{
			while (master->moves_min-- > 0)
				ft_rotate(stack_b, 1, "b");
		}
		while (master->moves_min-- > 0 && master->mod_min == 0)
			ft_rotate(stack_b, 0, "b");
	}
	else
	{
		i = master->moves_max;
		if (master->mod_max == 1)
		{
			while (master->moves_max-- > 0)
				ft_rotate(stack_b, 1, "b");
		}
		while (master->moves_max-- > 0 && master->mod_max == 0)
		{
			ft_rotate(stack_b, 0, "b");
		}
	}
	return (i);
}

int	find_median(unsigned int size, t_node *stack)
{
	int	*array;
	int	*sorted_array;
	unsigned int	i;

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
