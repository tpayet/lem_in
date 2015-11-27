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

/*
** STRUCT.C
*/
t_room				*find_special(t_room *room, const int special);
void				gimme_weight(t_room *room, const int i);
char				**ant_array(int ant);
void				debug_arr(char **arr);

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
t_room				*read_file(const char *path, int *const ant);

#endif
