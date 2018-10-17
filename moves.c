/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:51:12 by amoodley          #+#    #+#             */
/*   Updated: 2017/11/27 15:29:14 by amoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	move_to(t_map *map, int *loop)
{
	map->rooms[map->k]->full += 1;
	map->ants[map->j]->room = map->rooms[map->k]->name;
	ft_putstr("L");
	ft_putstr(map->ants[map->j]->name);
	ft_putstr("-");
	ft_putstr(map->rooms[map->k]->name);
	ft_putstr(" ");
	map->move = 1;
	map->l = 0;
	*loop = 1;
}

int		move_from(t_map *map)
{
	if (ft_strcmp(map->paths[map->i][map->ants[map->j]->index - 1],
				map->rooms[map->l]->name) == 0)
	{
		map->rooms[map->l]->full -= 1;
		return (1);
	}
	return (0);
}

void	valid(t_map *map, int *loop)
{
	if (map->rooms[map->k]->full == 0 && map->rooms[map->k]->end == 0)
	{
		move_to(map, loop);
		while (map->rooms[map->l])
		{
			if (move_from(map) == 1)
				break ;
			map->l++;
		}
		map->ants[map->j]->index += 1;
	}
	else if (map->rooms[map->k]->end == 1)
	{
		map->ants[map->j]->end = 1;
		move_to(map, loop);
		while (map->rooms[map->l])
		{
			if (move_from(map) == 1)
				break ;
			map->l++;
		}
		map->ants[map->j]->index += 1;
	}
}
