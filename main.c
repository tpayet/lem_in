/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 19:07:56 by tpayet            #+#    #+#             */
/*   Updated: 2015/10/08 19:07:57 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*new_room(const char *name, const int special)
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
	return (new);
}

void	room_add(t_room **list, t_room *new)
{
	if (!list || !new)
		return ;
	new->next = *list;
	*list = new;
}

t_link	*new_link(t_room **linked_room)
{
	t_link	*new;

	if (!(new = malloc(sizeof(t_link))) || !linked_room)
		return (NULL);
	new->room = *linked_room;
	new->next = NULL;
	return (new);
}

void	link_add(t_room *room, t_link *new)
{
	if (!new || !room)
		return ;
	new->next = room->links;
	room->links = new;
}

void	fatal(const char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	seek_n_link(const char *str, t_room **room)
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

/*
** A FREE LES STRSPLIT
*/

int		parse_line(t_room **room, const char *str, const int special)
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

t_room	*read_file(const char *path, int *const ant)
{
	int		fd;
	char	*str;
	t_room	*room;
	int		special;

	special = NORMAL;
	fd = open(path, O_RDONLY);
	room = NULL;
	if (get_next_line(fd, &str))
		*ant = ft_atoi(str);
	while (get_next_line(fd, &str) > 0)
	{
		if (str[0] == '#' && str[1] != '#')
			continue ;
		special = parse_line(&room, str, special);
	}
	if (close(fd) != 0)
		fatal("Error while closing read file");
	gimme_weight(find_special(room, END), 0);
	if (((find_special(room, START))->weight) == -1)
		fatal("ERROR");
	return (room);
}

void	debug(const t_room *room)
{
	t_room *tmp = (t_room *)room;
	t_link *tmp2 = NULL;
	ft_putendl("-------------------------");
	while (tmp)
	{
		ft_putstr("Room->name : ");
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
		ft_putendl("\n-------------------------");
		tmp = tmp->next;
	}
}

int		room_cmp(t_room *r1, t_room *r2)
{
	return (r1->weight - r2->weight);
}

void	room_insert(t_room **list, t_room *elem)
{
	t_room *tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->next)
		{
			if (room_cmp(tmp->next, elem) <= 0)
				tmp = tmp->next;
			else
			{
				elem->next = tmp->next;
				tmp->next = elem;
				return ;
			}
		}
		else
		{
			tmp->next = elem;
			elem->next = NULL;
			return ;
		}
	}
}

void	sort_rooms(t_room **rooms)
{
	t_room *tmp;
	t_room *buff;

	tmp = *rooms;
	while (tmp && tmp->next)
	{
		if (room_cmp(tmp, tmp->next) > 0)
		{
			buff = tmp->next;
			tmp->next = buff->next;
			room_insert(rooms, buff);
			tmp = *rooms;
		}
			tmp = tmp->next;
	}
}

int		main(int argc, char **argv)
{
	t_room	*rooms;
	int		ant;

	ant = 0;
	if (argc != 2)
		fatal("Please give file as argument.");
	rooms = read_file(argv[1], &ant);
	(find_special(rooms, START))->ant = ant;
	// while (((find_special(rooms, START))->ant == 0) && \
	// 	((find_special(rooms, END))->ant == ant))
	// {

	// }
	debug(rooms);

	sort_rooms(&rooms);
	debug(rooms);
	return (0);
}
