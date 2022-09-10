/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <jhoule-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:20:33 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/09/08 09:24:51 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_node **stack, int reverse, char *a_or_b)
{
	t_node	*temp, *temp_prev;

	temp = *stack;
	temp_prev = (*stack)->prev;
	if (reverse == 0)
	{
		*stack = (*stack)->next;
		temp_prev->next = temp;
		(*stack)->prev = temp;

	}
	else
	{
		*stack = (*stack)->prev;
		(*stack)->next = temp;
		(*stack)->next->next->prev = temp;
	}
	if (reverse == 1)
		printf("\nrr%s", a_or_b);
	else
		printf("\nr%s", a_or_b);
	return (1);
}

int	ft_swap(t_node **stack, char *a_or_b)
{
	t_node	*temp;

	temp = malloc(sizeof(stack));
	temp->nbr = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = temp->nbr;
	free(temp);
	printf("\ns%s", a_or_b);
	return(1);
}

int	ft_push(t_node **stack_in, t_node **stack_out, t_var *master, char *a_or_b)
{
	t_node	*temp, *new;

	if (a_or_b[0] == 'a')
	{
		master->size_in = master->size_a;
		master->size_a += 1;
		master->size_b -= 1;
	}
	else
	{
		master->size_in = master->size_b;
		master->size_a -= 1;
		master->size_b += 1;
	}
	temp = *stack_out;
	new = malloc(sizeof(t_node));
	new->nbr = (*stack_out)->nbr;
	new->next = *stack_in;
	if (master->size_in == 1)
	{
		new->prev = *stack_in;
		(*stack_in)->next = new;
		(*stack_in)->prev = new;
	}	
	else if (master->size_in != 0)
	{
		new->prev = (*stack_in)->prev;
		(*stack_in)->prev->next = new;
		(*stack_in)->prev = new;
	}
	*stack_in = new;

	*stack_out = (*stack_out)->next;
	(*stack_out)->prev = temp->prev;
	temp->prev->next = *stack_out ;
	
	temp = NULL;
	free (temp);
	printf("\np%s", a_or_b);
	return(1);
} 

int	push_swap(t_var *master, int *initial_array)
{
	t_node	*a, *b;
	unsigned int	i;

	master->sorted_array = sort_array(initial_array, master->size_a);
	a = array_to_list(initial_array, master->size_a);
	master->ops = 0;
	master->size_b = 0;
	i = -1;
	if (is_it_ordered(a, master->size_a, master->sorted_array, 0) == 1)
	{
		printf("\nThe list is ordered");
		return (0);
	}
	ft_push(&b, &a, master, "b");
//	if (master->size_a <= 3)
//		three_args(&a, size_a, 0, sorted_array, &ops);	
//	else if (master->size_a == 4 || size_a == 5)
//		master->size_b = five_args(&a, &b, &size_a, sorted_array, &ops);
//	master->size_b = hundred_args(&a, &b);
//	printf("\nNumber of operations: %u", master->ops);
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
