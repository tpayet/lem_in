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

//PERMET DE CHERCHER LA MEILLEURE OPTION OU ALLER EN FONCTION DU POIDS
// IL FAUT RAJOUTER UNE CONDITION SI LENDROIT EST PLEIN OU SI ON PEUT ALLER A LA FIN

// t_room	*where_to_go(t_room *actual_room)
// {
// 	t_room	*best_place;
// 	t_link	*tmp;

// 	best_place = NULL;
// 	tmp = actual_room->links;
// 	while (tmp)
// 	{
// 		if (tmp == find_special)
// 		else if (!best_place && tmp->room->weight <= actual_room->weight && tmp->room->ant == 0)
// 			best_place = tmp->room;
// 		else if (tmp->room->weight < best_place->weight && tmp->room-ant == 0)
// 			best_place = tmp->room;
// 		tmp = tmp->next;
// 	}
// 	return (best_place);
// }


//PERMET DE DEPLACER UNE FOURMI DUNE SALLE A LAUTRE
void	ant_move(t_room *actual, t_room *next)
{
	actual->ant -= 1;
	next->ant += 1;
	next->a_name = ft_strdup(actual->a_name);
	// free(actual->a_name);
	actual->a_name = NULL;
	ft_putstr(actual->a_name);
	ft_putstr(next->a_name);
	ft_putstr("-->");
	ft_putstr(next->name);
	ft_putchar(' ');
}

//PERMET DE COMPTER LES DIFFERENTES SALLES OU JE PEUX ALLER (UTILE POUR LE DEPART)
int		count_options(t_room *room, const int w)
{
	t_link	*tmp;
	int		count;

	count = 0;
	tmp = room->links;
	while (tmp)
	{
		if (tmp->room->weight == w)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

//PERMET DE COMPTER COMBIEN DE FOURMI JE DOIS FAIRE PARTIR PAR TOUR
int		how_much(const int ant, t_room *room, int nb, int const w)
{
	int		tmp;

	tmp = count_options(room, w);
	nb += tmp;
	if (nb * 2 > ant || tmp == 0)
		return (nb);
	else
		return (how_much(ant, room, nb, w + 1));
}

// void	first_move(t_room *start, char **arr)

//GERE UN TOUR POUR AVANCER TOUT LE MONDE, A GERER:
// LA GESTION DE LA PREMIERE ROOM
// void	tour(t_room *room, tour)
// {
// 	t_room *tmp;
// 	t_room *target;

// 	tmp = room;
// 	target = NULL;
// 	while (tmp)
// 	{
// 		if (tmp->special == START && tmp->ant > 0)
// 		{
// 			first_move(tmp);
// 		}
// 		else if ((target = where_to_go(tmp)) && tmp->ant == 1)
// 		{
// 			ant_move(tmp, target);
// 			target = NULL;
// 		}
// 		tmp = tmp->next;
// 	}
// }

t_room	*best_place_to_go(t_room *room)
{
	t_link	*tmp_link;
	t_room	*best_room;

	tmp_link = room->links;
	best_room = NULL;
	while (tmp_link)
	{
		if (tmp_link->room->special == 2)
			return (tmp_link->room);
		if (tmp_link->room->ant == 0 && tmp_link->room->weight < room->weight)
			if (!best_room || best_room->weight > tmp_link->room->weight)
				best_room = tmp_link->room;
		tmp_link = tmp_link->next;
	}
	return (best_room);
}

t_room	*get_room_by_name(t_room *room, char *name)
{
	if (!room)
		return (NULL);
	else if (!ft_strcmp(room->name, name))
		return (room);
	else
		return get_room_by_name(room->next, name);
}

void	first_round(t_room *first_room, char **arr_ant)
{
	t_room *tmp;

	tmp = NULL;
	if (arr_ant)
	{
		while ((tmp = best_place_to_go(first_room)))
		{
			// ft_putstr("main.c first_round l150\n");
			tmp->a_name = ft_strdup(*arr_ant);
			tmp->ant += 1;
			ft_putstr(*arr_ant++);
			ft_putstr("->");
			ft_putstr(tmp->name);
			ft_putstr("\n");
		}
	}
}

int		main_loop(t_room *rooms, int n_ant, char **arr_ant)
{
	t_room	*tmp;
	t_room	*b_p_t_g;

	tmp = rooms;
	b_p_t_g = NULL;
	debug(rooms);
	ft_putstr("\nNew turn*****************************************\n");
	if (tmp->ant == n_ant)
		return (0);
	else
	{
		// ft_putstr("main.c main_loop l171\n");
		while (tmp)
		{
			if (!tmp->special && arr_ant)
				first_round(tmp, arr_ant);
			else
			{
				if (tmp->ant && (b_p_t_g = best_place_to_go(tmp)))
				{
					ft_putstr(tmp->a_name);
					ft_putnbr(tmp->ant);
					ft_putstr("ahahah");
					ant_move(tmp, b_p_t_g);
					ft_putstr(tmp->a_name);
					ft_putnbr(tmp->ant);
					ft_putstr("lol");
					// debug(rooms);
					// ft_putstr("main.c main_loop l181\n");
				}
			}
			tmp = tmp->next;
		}
	}
	return (main_loop(rooms, n_ant, arr_ant));

}

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
	// (find_special(rooms, START))->ant = ant;
	rooms = sort_room(rooms);
	// debug(rooms);
	ft_putchar('\n');
	// t_room *tmp = best_place_to_go(get_room_by_name(rooms, "0"));
	// if (tmp!= NULL)
		// ft_putstr(tmp->name);
	// else
		// ft_putstr("NULL\n");
	char **ttmp = arr_ant;
	while (*ttmp)
		ft_putstr(*ttmp++);
	main_loop(rooms, 1, arr_ant);
	// ft_putendl((where_to_go(find_special(rooms, START)))->name);
	// t_room *start = find_special(rooms, START);
	// ft_putnbr(count_options(start, start->weight - 2));
	// ft_putnbr(how_much(ant, start, 0, (where_to_go(start))->weight));
	return (0);
}
