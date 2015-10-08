/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 11:08:55 by tpayet            #+#    #+#             */
/*   Updated: 2014/11/13 17:50:30 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *old, size_t old_size, size_t new_size)
{
	void	*new;

	if (!(new = (void *)ft_memalloc(new_size ? sizeof(old) * new_size : 1)))
		return (NULL);
	if (old)
	{
		ft_memcpy(new, old, (old_size > new_size) ? (new_size) : (old_size));
		ft_memdel((void *)&old);
	}
	return (new);
}
