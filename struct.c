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
	arr[ant] = NULL;
	ant -= 1;
	while (ant >= 0)
	{
		arr[ant] = ft_strjoin("L", ft_itoa(ant + 1));
		ant--;
	}
	return (arr);
}

void	gimme_weight(t_room *room, const int i)
{
	t_link	*tmp;

	tmp = NULL;
	if (!room)
		fatal("ERROR");
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

/*
** PERMET DE DEPLACER UNE FOURMI DUNE SALLE A LAUTRE
*/

void	ant_move(t_room *actual, t_room *next)
{
	actual->ant -= 1;
	next->ant += 1;
	next->a_name = ft_strdup(actual->a_name);
	free(actual->a_name);
	actual->a_name = NULL;
	ft_putstr(actual->a_name);
	ft_putstr(next->a_name);
	ft_putstr("->");
	ft_putstr(next->name);
	ft_putchar(' ');
}
