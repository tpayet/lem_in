/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:57:45 by tpayet            #+#    #+#             */
/*   Updated: 2014/11/06 15:14:02 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*swp;
	size_t	i;

	swp = malloc(len);
	if (!swp)
		return (NULL);
	i = 0;
	ft_memcpy(swp, src, len);
	while (i < len)
	{
		((char *)dst)[i] = swp[i];
		i++;
	}
	free(swp);
	return (dst);
}
