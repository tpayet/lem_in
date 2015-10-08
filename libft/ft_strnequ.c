/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:18:50 by tpayet            #+#    #+#             */
/*   Updated: 2014/11/12 16:31:24 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s2);
	if (ft_strlen(s1) > len && n > len)
		return (0);
	else
		return (!ft_strncmp(s1, s2, n));
}
