/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:56:53 by tpayet            #+#    #+#             */
/*   Updated: 2014/11/13 16:41:48 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && s2)
		return ((unsigned char)(-*s2));
	else if (s1 && !s2)
		return ((unsigned char)(*s1));
	else if (!s1 && !s2)
		return (0);
	while (*s1 && *s2)
	{
		if (*s1++ != *s2++)
			return ((unsigned char)*--s1 - (unsigned char)(*--s2));
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
