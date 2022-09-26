/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <jhoule-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:20:33 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/09/26 10:12:13 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_var *master, int *initial_array)
{
	t_node	*a, *b;
	unsigned int	i;

	master->sorted_array = sort_array(initial_array, master->size_a);
	a = array_to_list(initial_array, master->size_a);
	master->ops = 0;
	master->size_b = 0;
	i = -1;
	if (is_it_ordered(a, master, master->size_a, 0) == 1)
	{
		printf("\nThe list is ordered");
		return (0);
	}
	if (master->size_a <= 3)
		three_args(&a, master, "a");
	else if (master->size_a == 4 || master->size_a == 5)
		five_args(&a, &b, master);
	else if (master->size_a > 5 && master->size_a <= 500)
		hundred_args(&a, &b, master);
	printf("\nNumber of operations: %u", master->ops);
	printf("\nA: ");	
	i = -1;
	while (++i < master->size_a)
	{
		printf("%d ", a->nbr);
		a = a->next;
	}	
	printf("\nB: ");
	i = -1;
	while (++i < master->size_b)
	{
		printf("%d ", b->nbr);
		b = b->next;
	} 
	return (0); 
}

void	parsing(int *initial_array, int argc)
{
	int	i;
	int	o;

	i = -1;
	o = -1;
	while (
}

int	main(int argc, char **argv)
{
	int	*initial_array;
	int	i;
	t_var *master;

	master = malloc(sizeof(t_var));
	initial_array = malloc(sizeof(int) * argc);
	master->original_size = argc - 1;
	master->size_a = argc - 1;
	i = -1;
	while (++i < argc - 1)
	{
		initial_array[i] = atoi(argv[i + 1]); 		//attention atoi!
	}
	
	push_swap(master, initial_array); 
}
