/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 12:23:17 by tpayet            #+#    #+#             */
/*   Updated: 2015/10/09 12:23:20 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_link	*new_link(t_room **linked_room)
{
	t_link	*new;

	if (!(new = malloc(sizeof(t_link))) || !linked_room)
		return (NULL);
	new->room = *linked_room;
	new->next = NULL;
	return (new);
}

static void		link_add(t_room *room, t_link *new)
{
	if (!new || !room)
		return ;
	new->next = room->links;
	room->links = new;
}

static void		seek_n_link(const char *str, t_room **room)
{
	char	**arr;
	t_room	*tmp;
	t_room	*tmp2;

	arr = ft_strsplit(str, '-');
	tmp = *room;
	tmp2 = *room;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, arr[0]))
		{
			while (tmp2)
			{
				if (!ft_strcmp(tmp2->name, arr[1]))
				{
					link_add(tmp, new_link(&tmp2));
					link_add(tmp2, new_link(&tmp));
					break ;
				}
				tmp2 = tmp2->next;
			}
			break ;
		}
		tmp = tmp->next;
	}
}

static int		parse_line(t_room **room, const char *str, const int special)
{
	if (!ft_strcmp("##start", str))
		return (START);
	else if (!ft_strcmp("##end", str))
		return (END);
	else
	{
		if (ft_strchr(str, '-'))
			seek_n_link(str, room);
		else if (ft_strchr(str, ' '))
		{
			if (!(*room))
				*room = new_room((ft_strsplit(str, ' '))[0], special);
			else
				room_add(room, new_room((ft_strsplit(str, ' '))[0], special));
		}
		return (NORMAL);
	}
}

t_room			*read_file(int *const ant)
{
	char	*str;
	t_room	*room;
	t_room	*start_room;
	int		special;

	special = NORMAL;
	room = NULL;
	if (get_next_line(0, &str))
		*ant = ft_atoi(str);
	ft_putendl(str);
	while (get_next_line(0, &str) > 0)
	{
		ft_putendl(str);
		if (str[0] == '#' && str[1] != '#')
			continue ;
		special = parse_line(&room, str, special);
	}
	gimme_weight(find_special(room, END), 0);
	if (!(start_room = find_special(room, START)))
		fatal("ERROR");
	else if ((start_room->weight) == -1)
		fatal("ERROR");
	return (room);
}
