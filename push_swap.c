/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <jhoule-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:20:33 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/10/06 11:04:50 by jhoule-l         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	*initial_array;
	int	i;
	t_var *master;

	if (argc < 2)
	{
		printf("\n");
		return (0);
	}
//	printf("%d", is_split_needed(argv[1]));
	if (is_split_needed(argv[1]) == 1)
		argv = ft_split(argv[1], ' ', &argc);
	if (non_integer(argc, argv) == 1)
	{
		printf("Error\n");
		return (0);
	}
	if (int_limit(argc, argv) == 1)
	{
		printf("Error2\n");
		return (0);
	}
	
	initial_array = create_initial_array(argc, argv); 		
	master = malloc(sizeof(t_var));
	master->original_size = argc - 1;
	master->size_a = argc - 1;
	i = -1;
	push_swap(master, initial_array); 
}
