/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:10:47 by amoodley          #+#    #+#             */
/*   Updated: 2017/11/27 14:46:56 by amoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_loop(t_map *map)
{
	int		loop;

	loop = 0;
	while (map->rooms[map->k])
	{
		if ((ft_strcmp(map->paths[map->i][map->ants[map->j]->index],
						map->rooms[map->k]->name) == 0) &&
				(ft_strcmp(map->paths[map->i][map->ants[map->j]->index - 1],
						map->ants[map->j]->room) == 0))
		{
			valid(map, &loop);
			if (loop == 1)
				break ;
		}
		map->k++;
	}
}

void	path_loop(t_map *map)
{
	while (map->paths[map->i])
	{
		map->k = 0;
		if (map->ants[map->j]->index < array_len(map->paths[map->i]))
		{
			room_loop(map);
		}
		if (map->move == 1)
		{
			map->move = 0;
			break ;
		}
		map->i++;
	}
}

void	ant_loop(t_map *map)
{
	while (map->ants[map->j])
	{
		map->i = 0;
		if (map->ants[map->j]->end != 1)
		{
			path_loop(map);
		}
		map->j++;
	}
}
