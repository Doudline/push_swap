/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 08:37:24 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/09/08 08:43:46 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	void	*prev;
	int		nbr;
	void	*next;
}	t_node;

typedef struct s_master_node
{
	t_node	a;
	t_node	b;
}	t_master_node;

int	main()
{
	t_master_node *master;

	master = malloc(sizeof(t_master_node));

	master->a.nbr = 5;
	printf("%d", master->a.nbr);
}
