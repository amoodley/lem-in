/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:17:04 by amoodley          #+#    #+#             */
/*   Updated: 2017/11/27 14:37:52 by amoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>

typedef struct		s_ant
{
	char			*name;
	char			*room;
	int				end;
	unsigned int	index;
}					t_ant;

typedef struct		s_room
{
	char			*name;
	int				start;
	int				end;
	int				full;
	int				visited;
	struct s_room	*rooms[10000];
}					t_room;

typedef struct		s_map
{
	char			*file;
	int				number_of_ants;
	int				start;
	int				end;
	char			**links;
	int				link_start;
	int				link_end;
	int				count;
	char			**split;
	t_room			*rooms[10000];
	int				room_index;
	t_ant			**ants;
	char			***paths;
	int				path_index;
	int				i;
	int				j;
	int				k;
	int				l;
	int				move;
}					t_map;

typedef struct		s_path
{
	char			*data;
	struct s_path	*next;
}					t_path;

void				get_file_contents(t_map *map);
void				set_room_position(t_map *map);
void				room_create(t_map *map);
void				link_create(t_map *map);
void				ant_create(t_map *map);
void				check_room_position(t_map *map);
void				route_list(t_map *map);
void				find_routes(t_room *s, t_path *h, t_path *l, t_map *map);
void				save_route(t_path *head, t_map *map);
void				sort(char ***arr);
void				exit_function(void);
size_t				array_len(char **arr);
void				ant_loop(t_map *map);
void				path_loop(t_map *map);
void				room_loop(t_map *map);
void				valid(t_map *map, int *loop);
int					move_from(t_map *map);
void				free_ants(t_map *map);
void				free_paths(t_map *map);
void				free_rooms(t_map *map);
void				frees(t_map *map);
void				free2d(char **arr);

#endif
