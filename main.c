/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:04:49 by amoodley          #+#    #+#             */
/*   Updated: 2017/11/27 13:40:41 by amoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	exit_function(void)
{
	ft_putendl("ERROR");
	exit(0);
}

size_t	array_len(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	check_room_position(t_map *map)
{
	map->start = 0;
	map->end = 0;
	while (map->rooms[map->start]->start == 0)
		if (map->rooms[++map->start] == NULL)
			exit_function();
	while (map->rooms[map->end]->end == 0)
		if (map->rooms[++map->end] == NULL)
			exit_function();
	map->rooms[map->start]->full = map->number_of_ants;
}

void	ant_create(t_map *map)
{
	int		i;

	i = 0;
	map->ants = (t_ant **)malloc(sizeof(t_ant *) * map->number_of_ants + 1);
	while (i < map->number_of_ants)
	{
		map->ants[i] = (t_ant *)ft_memalloc(sizeof(t_ant));
		map->ants[i]->name = ft_itoa(i + 1);
		map->ants[i]->index = 1;
		map->ants[i]->room = map->rooms[map->start]->name;
		map->ants[i]->end = 0;
		i++;
	}
	i = 0;
	while (map->rooms[i])
	{
		map->rooms[i]->visited = 0;
		i++;
	}
}

int		main(void)
{
	t_map	map;

	ft_bzero(&map, sizeof(t_map));
	get_file_contents(&map);
	if (map.count == 0)
		exit_function();
	check_room_position(&map);
	ant_create(&map);
	route_list(&map);
	if (!map.paths[0])
		exit_function();
	ft_putstr("\n");
	while (map.rooms[map.end]->full < map.number_of_ants)
	{
		map.j = 0;
		ant_loop(&map);
		ft_putstr("\n");
	}
	free_rooms(&map);
	free_paths(&map);
	free_ants(&map);
	return (0);
}
