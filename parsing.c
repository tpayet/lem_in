/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 12:23:17 by tpayet            #+#    #+#             */
/*   Updated: 2015/10/09 12:23:20 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// char	*find_start(char *str)
// {
// 	char	**array;
// 	int		i;

// 	i = 0;
// 	array = ft_strsplit(str, '\n');
// 	while (array[i])
// 	{
// 		if (!ft_strcmp(array[i], "##start"))
// 			return (array[i + 1]);
// 		i++;
// 	}
// 	return (NULL);
// }

// t_ant	**construct_ants_list(char *parse)
// {
// 	int		n;
// 	int		i;
// 	t_ant	**ants;
// 	char	*start;

// 	i = 0;
// 	n = ft_atoi(parse);
// 	start = find_start(parse);
// 	ants = malloc(sizeof(t_ant) * (n + 1));
// 	while (i < n)
// 	{
// 		ants[i] = malloc(sizeof(t_ant));
// 		ants[i]->index = i + 1;
// 		ants[i]->room = ft_strdup(start);
// 		i++;
// 	}
// 	ants[n] = NULL;
// 	return (ants);
// }


// ** parse_map takes pointers to rooms'array and ants'list
// ** and returns and 0 on success or any error
// ** buff is buffer for get_next_line, parse is the whole file which was read
// ** and parse is send to functions for constructions of rooms'array and
// ** ants'list


// int		parse_map(t_room ***rooms, t_ant **ants)
// {
// 	char	*buff;
// 	char	*parse;

// 	buff = NULL;
// 	parse = NULL;
// 	while (get_next_line(0, &buff) >= 0)
// 	{
// 		if (!parse)
// 			parse = ft_strcpy(ft_strnew(ft_strlen(buff)), buff);
// 		else
// 			parse = ft_strcat(ft_strcat(parse, "\n"), buff);
// 		if (*buff == 0)
// 			break ;
// 	}
// 	if (parse == NULL)
// 		return (E_PARSE);
// 	else
// 	{
// 		ants = construct_ants_list(parse);
// 		return (0);
// 	}
// }
