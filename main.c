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

t_room	*where_to_go(t_room *actual_room)
{
	t_room	*best_place;
	t_link	*tmp;

	best_place = NULL;
	tmp = actual_room->links;
	while (tmp)
	{
		if (tmp == find_special)
		else if (!best_place && tmp->room->weight <= actual_room->weight && tmp->room->ant == 0)
			best_place = tmp->room;
		else if (tmp->room->weight < best_place->weight && tmp->room-ant == 0)
			best_place = tmp->room;
		tmp = tmp->next;
	}
	return (best_place);
}


//PERMET DE DEPLACER UNE FOURMI DUNE SALLE A LAUTRE
void	ant_move(t_room *actual, t_room *next)
{
	actual->ant = 0;
	next->ant = 1;
	next->a_name = actual->a_name;
	actual->a_name = NULL;
	ft_putstr(actual->a_name);
	ft_putchar('-');
	ft_putstr(actual->name);
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

void	first_move(t_room *start, char **arr)

//GERE UN TOUR POUR AVANCER TOUT LE MONDE, A GERER:
// LA GESTION DE LA PREMIERE ROOM
void	tour(t_room *room, tour)
{
	t_room *tmp;
	t_room *target;

	tmp = room;
	target = NULL;
	while (tmp)
	{
		if (tmp->special == START && tmp->ant > 0)
		{
			first_move(tmp);
		}
		else if ((target = where_to_go(tmp)) && tmp->ant == 1)
		{
			ant_move(tmp, target);
			target = NULL;
		}
		tmp = tmp->next;
	}
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
	(find_special(rooms, START))->ant = ant;
	rooms = sort_room(rooms);
	debug(rooms);
	ft_putchar('\n');
	ft_putendl((where_to_go(find_special(rooms, START)))->name);
	t_room *start = find_special(rooms, START);
	// ft_putnbr(count_options(start, start->weight - 2));
	ft_putnbr(how_much(ant, start, 0, (where_to_go(start))->weight));
	return (0);
}
