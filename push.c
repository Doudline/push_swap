/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 08:51:46 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/09/10 10:28:48 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
