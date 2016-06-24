/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 19:08:04 by tpayet            #+#    #+#             */
/*   Updated: 2015/10/08 19:08:06 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LEM_IN_H
# define __LEM_IN_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# define START		0
# define END		2
# define NORMAL		1

struct s_link;

typedef struct		s_room
{
	char			*name;
	char			*a_name;
	int				weight;
	int				ant;
	int				special;
	int				index;
	struct s_room	*next;
	struct s_link	*links;
}					t_room;

typedef struct		s_link
{
	struct s_link	*next;
	t_room			*room;
}					t_link;

/*
** MAIN.C
*/
void				fatal(const char *msg);
t_room				*best_place_to_go(const t_room *room);
int					main_loop(t_room *rooms, const int n_ant, char **arr_ant);
char				**first_round(t_room *first_room, char **arr_ant);

/*
** STRUCT.C
*/
t_room				*find_special(t_room *room, const int special);
void				gimme_weight(t_room *room, const int i);
char				**ant_array(int ant);
void				ant_move(t_room *actual, t_room *next);

/*
** ROOM.C
*/
t_room				*new_room(const char *name, const int special);
void				room_add(t_room **list, t_room *new);
t_room				*sort_room(t_room *room);
void				debug(const t_room *room);

/*
** PARSING.C
*/
t_room				*read_file(int *const ant);

#endif
