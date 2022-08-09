/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:20:33 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/08/04 10:30:57 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*swap(int *stack)
{
	int temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	return (stack);
}

int	*rotate(int	*stack, int size, int reverse)
{
	int	i;
	int	temp;

	if (reverse == 0)
	{
		i = 0;
		temp = stack[i];
		while (i < size - 1)
		{
			stack[i] = stack[i + 1];
			i++;
		}
	}
	else
	{
		i = size - 1;
		temp = stack[i];
		while (i > 0)
		{
			stack[i] = stack[i - 1];
			i--;
		}
	}
	stack[i] = temp;
	return (stack);
}

int	push(int *stack_1, int *stack_2, int size)
{
	int	i;

	stack_1[0] = stack_2[0];
	i = 0;
	while (i < size)
	{
		stack_2[i] = stack_2[i + 1];
		i++;
	}
	return (0);	
}

int	*push_swap(int *a, int size)
{
	int *b;
	int	*sorted_array;
	int	i = -1;

	b = malloc(size * 4);
	/*sorted_array = sort_array(a, size);
	while (++i < size)
		printf("%d ", sorted_array[i]);
	printf("\n"); */
	push(b, a, size);
	return (a);
}

int	main()
{
	int	a[] = {47, -2, 600, 1, -12, 555};
	int size = sizeof(a)/4;
	int	i = -1;
	while (++i < size)
		printf("%d ", a[i]);
	printf("\n");
	push_swap(a, size);
	i = -1;
	while (++i < size)
		printf("%d ", a[i]);
}
