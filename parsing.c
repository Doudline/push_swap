/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:34:13 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/10/06 10:56:21 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	non_integer(int argc, char **argv)
{
	int	i;
	int	o;

	i = 0;
	while (++i < argc)
	{
		o = 0;
		while (argv[i][o])
		{
			if (argv[i][o] < '0' || argv[i][o] > '9')	
				return (1);
			o++;
		}
	}
	return (0);
}

int	int_limit(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) > INT_MAX)
			return (1);
		if (ft_atoi(argv[i]) < INT_MIN)
		{
			return (1);
		}
	}
	return (0);
}

int	duplicates(int argc, int *initial_array)
{
	int	i;
	int	o;
	int	nbr;

	i = 0;
	o = -1;
	while (++o < argc - 1)
	{
		nbr = initial_array[i];
		while (initial_array[i++])
		{
			if (initial_array[i] == nbr)
				return (1);
		}
	}
	return (0);
} 

int	*create_initial_array(int argc, char **argv)
{
	int	*initial_array;
	int	i;
	
	initial_array = malloc(sizeof(int) * argc);
	i = -1;
	while (++i < argc - 1)
	{
		initial_array[i] = ft_atoi(argv[i + 1]);
	}
	return (initial_array);

}

long long	ft_atoi(const char *str)
{
	int	i;
	long long	neg;
	long long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && '9' >= str[i])
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * neg);
}
