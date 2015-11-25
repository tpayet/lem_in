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

t_room	*new_room(const char *name, int special)
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
	new->ant = NULL;
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

void	fatal(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	read_file(char *path)
{
	int fd;
	char *str;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &str))
	{
		ft_putendl(str);
	}
	return ;
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		fatal("Please give file as argument.");
	read_file(argv[1]);
	return (0);
}
