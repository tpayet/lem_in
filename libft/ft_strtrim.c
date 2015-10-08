/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 20:10:26 by tpayet            #+#    #+#             */
/*   Updated: 2014/11/12 20:21:27 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(const char *s)
{
	char	*swp;

	while (ft_isblank(*s))
		s++;
	swp = ft_strchr(s, '\0') - 1;
	while (ft_isblank(*swp))
		swp--;
	return (ft_strsub(s, 0, swp - s + 1));
}
