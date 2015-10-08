/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:34:23 by tpayet            #+#    #+#             */
/*   Updated: 2014/11/06 14:57:35 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*sdst;
	char	*ssrc;
	char	x;

	i = 0;
	sdst = (char *)dst;
	ssrc = (char *)src;
	x = (char)c;
	while (i < n)
	{
		if ((*sdst++ = *ssrc++) == x)
			return (sdst);
		i++;
	}
	return (NULL);
}
