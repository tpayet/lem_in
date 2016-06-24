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

t_room	*best_place_to_go(const t_room *room)
{
	t_link	*tmp_link;
	t_room	*best_room;

	tmp_link = room->links;
	best_room = NULL;
	while (tmp_link)
	{
		if (tmp_link->room->special == END)
			return (tmp_link->room);
		if (tmp_link->room->ant == 0 && tmp_link->room->weight < room->weight)
			if (!best_room || best_room->weight > tmp_link->room->weight)
				best_room = tmp_link->room;
		tmp_link = tmp_link->next;
	}
	return (best_room);
}

char	**first_round(t_room *first_room, char **arr_ant)
{
	t_room *tmp;

	tmp = NULL;
	while ((tmp = best_place_to_go(first_room)) && *arr_ant)
	{
		tmp->a_name = ft_strdup(*arr_ant);
		tmp->ant += 1;
		ft_putstr(*arr_ant);
		free(*arr_ant++);
		ft_putstr("->");
		ft_putstr(tmp->name);
		ft_putstr(" ");
	}
	return (arr_ant);
}

int		main_loop(t_room *rooms, const int n_ant, char **arr_ant)
{
	t_room	*tmp;
	t_room	*b_p_t_g;

	tmp = rooms;
	b_p_t_g = NULL;
	if (tmp->ant == n_ant)
		return (0);
	else
	{
		while (tmp)
		{
			if (tmp->special == START && *arr_ant)
				arr_ant = first_round(tmp, arr_ant);
			else if (tmp->ant && (b_p_t_g = best_place_to_go(tmp)))
				ant_move(tmp, b_p_t_g);
			tmp = tmp->next;
		}
		ft_putchar('\n');
		return (main_loop(rooms, n_ant, arr_ant));
	}
}

int		main(void)
{
	t_room	*rooms;
	int		ant;
	char	**arr_ant;

	rooms = sort_room(read_file(&ant));
	arr_ant = ant_array(ant);
	return (main_loop(rooms, ant, arr_ant));
}
