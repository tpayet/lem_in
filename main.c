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

void	fatal(const char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

t_room	*where_to_go(t_room *actual_room)
{
	t_room	*best_place;
	t_link	*tmp;

	best_place = NULL;
	tmp = actual_room->links;
	while (tmp)
	{
		if (best_place)
		{
			if (tmp->room->weight < best_place->weight && tmp->room->ant == 0)
				best_place = tmp->room;
			else
				continue ;
		}
		else if (tmp->room->weight < actual_room->weight && tmp->room->ant == 0)
			best_place = tmp->room;
		tmp = tmp->next;
	}
	return (best_place);
}

void	ant_move(t_room *actual, t_room *next)
{
	next->a_name = actual->a_name;
	actual->a_name = NULL;
	ft_putstr(actual->a_name);
	ft_putchar('-');
	ft_putstr(actual->name);
}

// void	tour(t_room *room)
// {
// 	t_room *tmp;
// 	t_room *target;

// 	tmp = room;
// 	target = NULL;
// 	while (tmp)
// 	{
// 		if (tmp->special == START)
// 		{
// 			while ((target = where_to_go(tmp)))
// 				first_move(tmp, target, i++);
// 		}
// 		else if ((target = where_to_go(tmp)))
// 		{
// 			ant_move(tmp, target);
// 			target = NULL;
// 		}
// 		tmp = tmp->next;
// 	}
// }

int		main(int argc, char **argv)
{
	t_room	*rooms;
	int		ant;
	char	**arr_ant;

	ant = 0;
	if (argc != 2)
		fatal("Please give file as argument.");
	rooms = read_file(argv[1], &ant);
	arr_ant = ant_array(ant);
	(find_special(rooms, START))->ant = ant;
	rooms = sort_room(rooms);
	debug(rooms);
	return (0);
}
