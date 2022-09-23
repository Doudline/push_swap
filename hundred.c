/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:33:11 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/09/23 10:06:12 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void moves_pusher(t_node **stack_a, t_node **stack_b, t_var *master)
{
	if (master->moves_beg <= master->moves_end)
	{
		while (master->moves_beg--)
			master->ops += ft_rotate(stack_a, 0, "a");
	}
	else
	{
		while (master->moves_end--)
			master->ops += ft_rotate(stack_a, 1, "a");
	}
	master->ops += ft_push(stack_b, stack_a, master, "b");
}

int	moves_from_beginning(t_node *stack, t_var *master)
{
	unsigned int	i;

	master->upper_bound = master->sorted_array[master->quantile];
	printf("\nlower, upper = %d %d\n", master->lower_bound, master->upper_bound);
	i = 0;
	while (i < master->original_size)
	{
		if (stack->nbr < master->upper_bound && stack->nbr >= master->lower_bound)
			break;
		i++;
		stack = stack->next;
	}
	printf("nbr = %d ", stack->nbr); 
	return (i);
}

int	moves_from_end(t_node *stack, t_var *master)
{
	unsigned int	i;

	master->upper_bound = master->sorted_array[master->quantile];
	printf("\nlower, upper = %d %d\n", master->lower_bound, master->upper_bound);
	i = 0;
	while (i < master->original_size)
	{
		if (stack->nbr < master->upper_bound && stack->nbr >= master->lower_bound)
			break;
		i++;
		stack = stack->prev;
	}
	printf("nbr = %d ", stack->nbr); 
	return (i);
}
