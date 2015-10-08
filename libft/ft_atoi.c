/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:00:31 by tpayet            #+#    #+#             */
/*   Updated: 2014/11/10 18:57:58 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_skipspace(const char *str)
{
	char	*str2;

	str2 = (char *)str;
	while (str2 && ft_isspace(*str2))
		str2++;
	return (str2);
}

int				ft_atoi(const char *str)
{
	size_t	i;
	int		res;
	int		sign;
	char	*str2;

	i = 0;
	res = 0;
	sign = 1;
	str2 = ft_skipspace(str);
	if (str2[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (*str2 == '+')
		str2++;
	while (str2[i] != '\0')
	{
		if (str2[i] > '9' || str2[i] < '0')
			return (res * sign);
		res = str2[i++] + res * 10 - 48;
	}
	return (res * sign);
}
