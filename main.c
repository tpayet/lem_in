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

int	main(int argc, char **argv)
{
	t_room	**rooms;
	t_ant	*ants;

	rooms = NULL;
	ants = NULL;
	if (argc != 1)
	{
		exit(ft_error(E_ARG, argv[0]));
	}
	else
	{
		parse_map(&rooms, &ants);
		// lem_in(rooms, ants);
	}
	// char	*buff;
	// buff = NULL;
	// while (get_next_line(0, &buff) >= 0)
	// {
	// 	ft_putstr(buff);
	// 	if (*buff == 0)
	// 	{
	// 		exit(1);
	// 	}
	// }
	return (0);
}