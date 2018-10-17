/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:18:19 by amoodley          #+#    #+#             */
/*   Updated: 2017/12/01 13:02:40 by amoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free2d(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	frees(t_map *map)
{
	if (map->file != NULL)
	{
		free(map->file);
		map->file = NULL;
	}
	if (map->links != NULL)
	{
		free2d(map->links);
		map->links = NULL;
	}
	if (map->split != NULL)
	{
		free2d(map->split);
		map->split = NULL;
	}
}

void	free_ants(t_map *map)
{
	int		i;

	i = 0;
	while (map->ants[i])
	{
		free(map->ants[i]->name);
		free(map->ants[i]);
		i++;
	}
	free(map->ants);
}

void	free_paths(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map->paths[i])
	{
		j = 0;
		while (map->paths[i][j])
		{
			free(map->paths[i][j]);
			j++;
		}
		free(map->paths[i]);
		i++;
	}
	free(map->paths);
}

void	free_rooms(t_map *map)
{
	int		i;

	i = 0;
	while (map->rooms[i])
	{
		free(map->rooms[i]->name);
		free(map->rooms[i]);
		i++;
	}
}
