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

# define E_ARG		974
# define E_PARSE	123

typedef struct s_room	t_room;
struct					s_room
{
	char				*name;
	int					weight;
	char				*ant;
	int					special;
	t_room				*next;
	struct s_link	*links;
};

typedef struct s_link	t_link;
struct					s_link
{
	t_room				*room;
	t_link				*next;
};


/*
** Parsing
*/

// int			parse_map(t_room ***rooms, t_ant **ants);
// t_ant		**construct_ants_array(char *parse);
// t_room		**construct_rooms_array(char *parse);

/*
** Error handling
*/
// 
// int			ft_error(int error, char *msg);

/*
** LEMIN
*/

// void		lem_in(t_room **rooms, t_ant *ants);

#endif
