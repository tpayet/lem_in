/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 19:12:33 by tpayet            #+#    #+#             */
/*   Updated: 2014/11/10 19:51:01 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*csr;
	char	*rdr;
	size_t	len;

	csr = (char *)(ft_memchr(dst, '\0', size));
	if (csr == NULL)
		return (size + ft_strlen(src));
	rdr = (char *)src;
	len = ((size_t)(csr - dst) + ft_strlen(rdr));
	while ((size_t)(csr - dst) < size - 1 && *rdr != '\0')
	{
		*csr = *rdr;
		csr++;
		rdr++;
	}
	*csr = '\0';
	return (len);
}
