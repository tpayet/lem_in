/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:34:39 by tpayet            #+#    #+#             */
/*   Updated: 2015/11/27 16:34:56 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*new_room(const char *name, const int special)
{
	t_room	*new;

	if (!(new = malloc(sizeof(t_room))))
		return (NULL);
	if (name)
		new->name = ft_strdup(name);
	else
		new->name = NULL;
	new->special = special;
	new->weight = -1;
	new->ant = 0;
	new->next = NULL;
	new->links = NULL;
	new->a_name = NULL;
	return (new);
}

void			room_add(t_room **list, t_room *new)
{
	if (!list || !new)
		return ;
	new->next = *list;
	*list = new;
}

static t_room	*room_switch(t_room *l1, t_room *l2)
{
	l1->next = l2->next;
	l2->next = l1;
	return (l2);
}

t_room			*sort_room(t_room *room)
{
	if (!room)
		return (NULL);
	if (room->next && room->weight > room->next->weight)
		room = room_switch(room, room->next);
	room->next = sort_room(room->next);
	if (room->next && room->weight > room->next->weight)
	{
		room = room_switch(room, room->next);
		room->next = sort_room(room->next);
	}
	return (room);
}

void			debug(const t_room *room)
{
	t_room *tmp;
	t_link *tmp2;

	tmp = (t_room *)room;
	while (tmp)
	{
		ft_putstr("\n--------------------\nRoom->name : ");
		ft_putendl(tmp->name);
		ft_putstr("Room->special : ");
		ft_putnbr(tmp->special);
		ft_putstr("\nRoom->ant : ");
		ft_putnbr(tmp->ant);
		ft_putstr("\nRoom->links :");
		tmp2 = tmp->links;
		while (tmp2)
		{
			ft_putstr(" ");
			ft_putstr(tmp2->room->name);
			tmp2 = tmp2->next;
		}
		ft_putchar('\n');
		ft_putstr("Room->weight : ");
		ft_putnbr(tmp->weight);
		tmp = tmp->next;
	}
}
