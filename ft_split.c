/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:04:47 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/10/06 09:47:12 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_split_needed(char const *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char sep, int *argc)
{
	char			**str;
	unsigned int	i;
	size_t			o;
	int				p;

	str = ft_calloc(sizeof(char *), (ft_count_words(s, sep) + 1));
	if (!str)
		return (NULL);
	*argc = ft_count_words(s, sep) + 1;
	i = 0;
	p = 0;
	while (++p < ft_count_words(s, sep) + 1)
	{
		while (s[i] == sep && s[i])
			i++;
		o = 0;
		while (s[i] != sep && s[i])
		{
			i++;
			o++;
			if (s[i] == sep || s[i] == '\0')
				str[p] = ft_substr(s, i - o, o);
		}
	}
	return (str);
}

static int	ft_count_words(char const *s, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == sep && s[i])
			i++;
		while (s[i] != sep && s[i])
		{
			if (s[i + 1] == sep || s[i + 1] == '\0')
				words++;
			i++;
		}
	}
	return (words);
}
