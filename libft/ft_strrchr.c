/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:13:47 by tpayet            #+#    #+#             */
/*   Updated: 2014/11/07 12:23:37 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *r;

	r = NULL;
	if (!str)
		return (r);
	while (*str)
	{
		if (*str == c)
			r = (char *)str;
		str++;
	}
	if (!c)
		r = (char *)str;
	return (r);
}
