/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:11:29 by amoodley          #+#    #+#             */
/*   Updated: 2017/12/01 12:58:23 by amoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_room_position(t_map *map)
{
	if (ft_strstr(map->file, "start"))
	{
		map->start = 1;
	}
	else if (ft_strstr(map->file, "end"))
	{
		map->end = 1;
	}
}

void	room_create(t_map *map)
{
	if (array_len(map->split) > 3)
		exit_function();
	map->rooms[map->room_index] = (t_room *)ft_memalloc(sizeof(t_room));
	map->rooms[map->room_index]->name = ft_strdup(map->split[0]);
	if (map->start == 1)
	{
		map->rooms[map->room_index]->start = 1;
		map->start = 0;
	}
	else if (map->end == 1)
	{
		map->rooms[map->room_index]->end = 1;
		map->end = 0;
	}
	map->room_index++;
}

void	link_create(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	map->links = ft_strsplit(map->split[0], '-');
	map->link_start = 0;
	map->link_end = 0;
	if (array_len(map->links) > 2 || map->rooms[map->link_start] == NULL)
		exit_function();
	while (ft_strcmp(map->rooms[map->link_start]->name, map->links[0]) != 0)
		if (map->rooms[++map->link_start] == NULL)
			exit_function();
	while (ft_strcmp(map->rooms[map->link_end]->name, map->links[1]) != 0)
		if (map->rooms[++map->link_end] == NULL)
			exit_function();
	while (map->rooms[map->link_start]->rooms[i])
		i++;
	while (map->rooms[map->link_end]->rooms[j])
		j++;
	map->rooms[map->link_start]->rooms[i] = map->rooms[map->link_end];
	map->rooms[map->link_end]->rooms[j] = map->rooms[map->link_start];
}

void	get_file_contents(t_map *map)
{
	while (get_next_line(0, &map->file) != 0)
	{
		ft_putendl(map->file);
		if (map->count < 1 && ft_isdigit(map->file[0]))
		{
			map->number_of_ants = ft_atoi(map->file);
			map->count++;
		}
		else if (map->count > 0)
		{
			if (map->file[0] == '#')
				set_room_position(map);
			else
			{
				map->split = ft_strsplit(map->file, ' ');
				if (map->split[0] == '\0')
					exit_function();
				else if (map->split[1] == NULL)
					link_create(map);
				else
					room_create(map);
			}
		}
	}
}
