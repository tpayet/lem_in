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
	t_room	*room;
};

/*
** Parsing
*/

t_ant		**construct_ants_array(char *arg);
t_room		**construct_rooms_array(char *arg);

#endif
