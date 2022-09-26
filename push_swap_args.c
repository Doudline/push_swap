/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 08:47:38 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/09/26 09:45:11 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hundred_args(t_node **stack_a, t_node **stack_b, t_var *master)
{
	master->lower_bound = master->sorted_array[0];
	if (master->original_size <= 100)
	{
		master->quantile = master->original_size / 3;
		solve_hundred(stack_a, stack_b, master);
	}
	else
	{
		master->quantile = master->original_size / 6;
		solve_five_hundred(stack_a, stack_b, master);
	}
} 

void	five_args(t_node **stack_a, t_node **stack_b, t_var *master)
{
	master->original_size = master->size_a;
	master->median = (master->sorted_array)[(master->original_size)/2];
	while (master->size_b < master->original_size/2)
	{
		if ((*stack_a)->nbr < master->median)
			master->ops += ft_push(stack_b, stack_a, master, "b");
		else
		{
			if ((*stack_a)->next->nbr < master->median)
				master->ops += ft_rotate(stack_a, 0, "a");
			else
				master->ops += ft_rotate(stack_a, 1, "a");	
		} 
	}
	three_args(stack_a, master, "a");
	three_args(stack_b, master, "b");
	while (master->size_b > 0)
		master->ops += ft_push(stack_a, stack_b, master, "a");
} 

void	three_args(t_node **stack, t_var *master, char *a_or_b)
{
	if (a_or_b[0] == 'b')
	{
		if (is_it_ordered(*stack, master, master->size_b,  0) == 0)	
			return;
		else
		{
			master->ops += ft_swap(stack, "b");
			return;
		}
	}
	while (is_it_ordered(*stack, master, master->original_size, master->size_b) != 1)
	{
		if ((*stack)->nbr > (*stack)->next->nbr)
			master->ops += ft_swap(stack, "a");
		else
			master->ops += ft_rotate(stack, 1, "a");
	}
	
}
