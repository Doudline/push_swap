/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 08:47:38 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/09/23 12:33:27 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hundred_args(t_node **stack_a, t_node **stack_b, t_var *master)
{
	t_node *temp;
	unsigned int	i;
	unsigned int	o;
	i = 0;
	o = 0;
	master->quantile = master->original_size / 3;
	master->lower_bound = master->sorted_array[0];
	while (i < master->quantile)
	{
		master->moves_beg = moves_from_beginning(*stack_a, master);
		master->moves_end = moves_from_end(*stack_a, master);
		moves_pusher(stack_a, stack_b, master);	
		i++;
	}
	sort_and_push(stack_b, stack_a, master);
	master->lower_bound = master->sorted_array[master->quantile];
	master->quantile += master->original_size / 3;
	while (i < master->quantile)
	{
		master->moves_beg = moves_from_beginning(*stack_a, master);
		master->moves_end = moves_from_end(*stack_a, master);
		moves_pusher(stack_a, stack_b, master);	
		i++;
	}
	while ((*stack_a)->prev->nbr >= master->lower_bound)
		master->ops += ft_rotate(stack_a, 1, "a");
	sort_and_push(stack_b, stack_a, master);
	while (i++ < master->original_size)
		master->ops += ft_push(stack_b, stack_a, master, "b");
	sort_and_push(stack_b, stack_a, master);
} 

void	five_args(t_node **stack_a, t_node **stack_b, t_var *master)
{
	master->original_size = master->size_a;
	master->median = (master->sorted_array)[(master->original_size)/2];
	printf("Median = %d %d", master->median, master->original_size/2);
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
		if (is_it_ordered(*stack, master, master->size_b,  0) == 0)	// on veut renvoyer b en sens inverse, donc on cherche retour 0
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
