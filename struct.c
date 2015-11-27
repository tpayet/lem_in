/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:41:00 by tpayet            #+#    #+#             */
/*   Updated: 2015/11/27 16:41:02 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**ant_array(int ant)
{
	char **arr;

	arr = (char **)malloc(sizeof(char *) * (ant + 1));
	arr[ant--] = NULL;
	while (ant >= 0)
	{
		arr[ant] = ft_strjoin("L", ft_itoa(ant));
		ant--;
	}
	return (arr);
}

void	debug_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_putstr(arr[i++]);
		ft_putstr("; ");
	}
}

void	gimme_weight(t_room *room, const int i)
{
	t_link	*tmp;

	tmp = NULL;
	if (room->weight == -1 || room->weight > i)
	{
		room->weight = i;
		tmp = room->links;
		while (tmp)
		{
			gimme_weight(tmp->room, (i + 1));
			tmp = tmp->next;
		}
	}
}

t_room	*find_special(t_room *room, const int special)
{
	t_room *tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->special == special)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
