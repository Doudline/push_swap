/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:41:35 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/08/04 10:10:48 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_array(int *stack, int size)
{
	int	i;
	int	temp;
	int	*array;

	array = malloc(size * 4);
	i = -1;
	while (++i < size)
		array[i] = stack[i];
	i = 0;
	while (i < size -1)
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
