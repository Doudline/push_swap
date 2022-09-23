/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:41:35 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/09/21 11:03:51 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_max(t_node *stack, int min_or_max, unsigned int size)
{
	int	min;
	int	max;
	unsigned int	i = 0;

	min = stack->nbr;
	max = stack->nbr;
	while (stack && i < size)
	{
		if (stack->nbr > max && min_or_max == 1)
			max = stack->nbr;
		else if (stack->nbr < min && min_or_max == 0)
			min = stack->nbr;
		stack = stack->next;
		i++;
	}
	if (min_or_max == 1)
		return (max);
	return (min);
}

int	is_it_in_array(int nbr, int *sorted_array, unsigned int start_index,
			unsigned int end_index)
{
	while (start_index < end_index)
	{
		if (sorted_array[start_index] == nbr)
			return (1);
		else
			start_index++;
	}
	return (0);
}

int	is_it_ordered(t_node *stack, t_var *master, unsigned int size, unsigned int index)
{
	while (index < size && stack)
	{
		if (stack->nbr != master->sorted_array[index])
			return (0);
		stack = stack->next;
		index++;
	}	
	return (1);
}

t_node *array_to_list(int *initial_array, unsigned int size)
{
	t_node	*head, *node;
	unsigned int	i;

	node = malloc(sizeof(t_node));
	if (node)
		head = node;
	i = 0;
	while (i < size && node)
	{
		node->nbr = initial_array[i];
		if (i + 1 == size)
		{
			node->next = head;
			head->prev = node;
			break;
		}
		node->next = malloc(sizeof(t_node));
		node->next->prev = node;
		node = node->next;
		i++;	
	}
	return (head);
}

int	*sort_array(int *stack, unsigned int size)
{
	unsigned int	i;
	int	temp;
	int	*array;

	array = malloc(size * 4);
	i = -1;
	while (++i < size)
		array[i] = stack[i];
	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			if (i > 0)
				i--;
		}
		else
			i++;
	}
	return (array);
}
