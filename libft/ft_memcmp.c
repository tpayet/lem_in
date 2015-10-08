/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:50:20 by tpayet            #+#    #+#             */
/*   Updated: 2014/11/10 20:09:18 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *swap1;
	const unsigned char *swap2;

	if (s1 != s2 && n)
	{
		swap1 = (const unsigned char *)s1;
		swap2 = (const unsigned char *)s2;
		while (n--)
		{
			if (*swap1 != *swap2)
				return (*swap1 - *swap2);
			swap1++;
			swap2++;
		}
	}
	return (0);
}
