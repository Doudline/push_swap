/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 08:47:38 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/09/08 08:52:15 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	hundred_args(t_node **stack_a, t_node **stack_b)
{
	t_node *temp;
	unsigned int	size_b = 0;
	unsigned int 	original_size = *size_a;
	unsigned int	i;
	unsigned int	lower_bound = 0;
	unsigned int	upper_bound = 0;
	unsigned int	quantile = 0;

	while (is_it_ordered(*stack_a, *size_a, sorted_array, 0) != 1)
	{
		quantile += *size_a / 2;
		lower_bound = sorted_array[quantile - 5];
		upper_bound = sorted_array[quantile - 1];
		while (size_b < 5)	
		{
			temp = *stack_a;
			if ((*stack_a)->nbr <= upper_bound && (*stack_a)->nbr >= lower_bound)
				*ops += ft_push(stack_b, stack_a, &size_b, size_a, "b");		
			else
			{
				i = 0;
				while (is_it_in_array(temp->nbr, sorted_array, quantile - 5, quantile) != 1)
				{
					temp = temp->next;
					i++;
				}
				if (i < *size_a/2)
				{	
					while (i-- > 0)
						*ops += ft_rotate(stack_a, 0, "a");
				}
				else
				{
					while (i++ < *size_a)
						*ops += ft_rotate(stack_a, 1, "a");
				}
			}
		}
		sort_and_push(stack_b, stack_a, &size_b, size_a, ops);	
	}
	return (size_b);	
}

unsigned int	five_args(t_node **stack_a, t_node **stack_b,  unsigned int *size_a,
	   		int *sorted_array, unsigned int *ops)
{
	int	median;
	unsigned int	size_b = 0;
	unsigned int	original_size = *size_a;

	median = sorted_array[(original_size)/2];
	printf("Median = %d", median);
	while (size_b < original_size/2)
	{
		if ((*stack_a)->nbr < median)
			*ops += ft_push(stack_b, stack_a, &size_b, size_a, "b");
		else
		{
			if ((*stack_a)->next->nbr < median)
				*ops += ft_rotate(stack_a, 0, "a");
			else
				*ops += ft_rotate(stack_a, 1, "a");	
		} 
	}
	three_args(stack_a, *size_a, size_b, sorted_array, ops);
	three_args(stack_b, size_b, *size_a, sorted_array, ops);
	while (size_b > 0)
		*ops += ft_push(stack_a, stack_b, size_a, &size_b, "a");
	return (size_b);
} 

void	three_args(t_node **stack, unsigned int size_stack, unsigned int size_other, int *sorted_array,
			unsigned int *ops)
{
	if (size_stack < size_other)
	{
		if (is_it_ordered(*stack, size_stack, sorted_array, 0) == 0)
			return;
		else
		{
			*ops += ft_swap(stack, "b");
			return;
		}
	}
	while (is_it_ordered(*stack, size_stack + size_other, sorted_array, size_other) != 1)
	{
		if ((*stack)->nbr > (*stack)->next->nbr)
			*ops += ft_swap(stack, "a");
		else
			*ops += ft_rotate(stack, 1, "a");
	}
	
}
