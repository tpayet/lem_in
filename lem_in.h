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

# define E_ARG		974
# define E_PARSE	123

typedef struct s_room	t_room;
struct		s_room
{
	char	*name;
	int		index;
	int		weight;
	int		full;
	t_room	**next_rooms_arr;
	t_room	**prev_rooms_arr;
};

typedef struct s_ant	t_ant;
struct		s_ant
{
	int		index;
	char	*room;
	t_ant	*next;
};

/*
** Parsing
*/

int			parse_map(t_room ***rooms, t_ant **ants);
t_ant		**construct_ants_array(char *parse);
// t_room		**construct_rooms_array(char *parse);

/*
** Error handling
*/

int			ft_error(int error, char *msg);

/*
** LEMIN
*/

// void		lem_in(t_room **rooms, t_ant *ants);

#endif
