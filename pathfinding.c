/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:57:22 by amoodley          #+#    #+#             */
/*   Updated: 2017/11/27 14:43:48 by amoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	save_route(t_path *head, t_map *map)
{
	t_path	*lst;
	int		i;
	char	**path;

	lst = head;
	i = 0;
	while (lst && lst->data)
	{
		i++;
		lst = lst->next;
	}
	path = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	lst = head;
	i = 0;
	while (lst && lst->data)
	{
		path[i] = ft_strdup(lst->data);
		i++;
		lst = lst->next;
	}
	map->paths[map->path_index] = path;
	map->path_index += 1;
}

void	find_routes(t_room *s, t_path *h, t_path *l, t_map *map)
{
	int		i;
	t_path	*next;

	i = 0;
	l->next = (t_path *)ft_memalloc(sizeof(t_path));
	s->visited = 1;
	l->data = s->name;
	next = l->next;
	if (s->end == 1)
	{
		free(next);
		l->next = NULL;
		save_route(h, map);
	}
	while (s->rooms[i] && s->end == 0)
	{
		if (s->rooms[i]->visited == 0)
			find_routes(s->rooms[i], h, next, map);
		i++;
	}
	s->visited = 0;
}

void	route_list(t_map *map)
{
	t_path	*path;

	path = (t_path *)ft_memalloc(sizeof(t_path));
	map->paths = (char ***)ft_memalloc(sizeof(char **) * 10000);
	find_routes(map->rooms[map->start], path, path, map);
	sort(map->paths);
	free(path);
}

void	sort(char ***arr)
{
	char	**ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (array_len(arr[i]) > array_len(arr[j]))
			{
				ptr = arr[i];
				arr[i] = arr[j];
				arr[j] = ptr;
			}
			j++;
		}
		i++;
	}
}
