/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:14:11 by tpayet            #+#    #+#             */
/*   Updated: 2014/12/01 17:44:14 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_relloc(char *str, int size)
{
	char		*new;

	if (str == NULL)
		return (ft_strnew(size));
	else
	{
		new = ft_strnew(ft_strlen(str) + size);
		if (!new)
			return (NULL);
		ft_strcpy(new, str);
		free(str);
		return (new);
	}
}

static char	*ft_splitline(char *str, char **reste)
{
	char		*new;
	size_t		len;

	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	new = ft_strsub(str, 0, len);
	free(*reste);
	if (len < ft_strlen(str))
		*reste = ft_strsub(str, len + 1, (ft_strlen(str) - (len + 1)));
	free(str);
	return (new);
}

static int	ft_readtoline(char **str, int fd)
{
	char		*buff;
	int			ret;

	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) >= 0)
	{
		buff[ret] = '\0';
		*str = ft_strcat(ft_relloc(*str, ft_strlen(buff)), buff);
		if (ft_memchr(*str, '\n', ft_strlen(*str)) != NULL)
			break ;
	}
	free(buff);
	return (ret);
}

int			get_next_line(int const fd, char **line)
{
	static char	*reste;
	int			ret;
	int			res;

	res = 1;
	ret = 0;
	if (fd < 0 || !line)
		return (-1);
	*line = ft_strnew(1);
	if (reste)
	{
		free(*line);
		*line = ft_strdup(reste);
	}
	if (ft_memchr(*line, '\n', ft_strlen(*line)) == NULL)
		ret = ft_readtoline(line, fd);
	if (ret < 0)
		return (-1);
	if (ret == 0)
		return (2);
	*line = ft_splitline(*line, &reste);
	res = ((ret < BUFF_SIZE) && *line[0] == '\0') ? 0 : 1;
	return (res);
}
