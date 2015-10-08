/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:20:13 by tpayet            #+#    #+#             */
/*   Updated: 2014/11/10 15:49:34 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s2[j] == s1[i])
		{
			if (j == 0)
				k = i;
			j++;
		}
		else
			j = 0;
		i++;
		if (s2[j] == '\0')
			return ((char *)(s1 + k));
	}
	return (NULL);
}
