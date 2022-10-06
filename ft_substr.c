/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoule-l <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:15:45 by jhoule-l          #+#    #+#             */
/*   Updated: 2022/04/13 10:02:55 by jhoule-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	size_t			len_s;

	if (!s)
		return (NULL);
	str = (char *)(s);
	len_s = ft_strlen(s);
	i = -1;
	if (start > len_s)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (++i < len)
		str[i] = s[i + start];
	str[i] = '\0';
	return (str);
}
