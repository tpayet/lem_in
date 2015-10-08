/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 03:55:50 by tpayet            #+#    #+#             */
/*   Updated: 2015/02/12 19:19:18 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Read the first line in the specified file descriptor and fill a given string.
** Return 0 if fail, else 1.
*/

#include "libft.h"
#include <unistd.h>

static int	ft_strindex(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (!s[i])
			return (-1);
		i++;
	}
	return (i);
}

int			get_line(int const fd, char **a)
{
	int		i;
	int		stop;
	int		n;
	char	buf[BUFF_SIZE];

	if (!a || fd < 0)
		return (0);
	*a = ft_strnew(1);
	n = 0;
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		*a = (char *)ft_realloc((void *)*a, ft_strlen(*a), ft_strlen(*a) + i);
		ft_strcat(*a, buf);
		if ((stop = ft_strindex(*a, '\n')) != -1)
		{
			n = 1;
			break ;
		}
	}
	*a = ft_realloc((void *)*a, ft_strlen(*a), stop);
	if (!*a || i < 0 || !n)
		return (0);
	return (1);
}
