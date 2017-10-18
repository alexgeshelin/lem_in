/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:02:21 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/20 13:02:24 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	int				start;
	int				end;
	int				ant;
}				t_room;

typedef	struct	s_path
{
	int				*path;
	long			*ants;
	int				l;
	struct s_path	*next;
}				t_path;

typedef struct	s_farm
{
	long	ants;
	t_room	*rooms;
	int		**links;
	int		**map;
	int		n;

}				t_farm;

void			free_paths(t_path *paths);
void			free_input(char **input);
void			fill_list(t_path **paths, t_path *path);
void			enter_ants(t_farm *farm, t_path *paths);
void			move_ants(t_farm *farm, t_path *paths);
void			go_ants_go(t_farm *farm, t_path *paths);
void			delete_links(t_farm *farm, t_path *path);
int				find_end(t_room *rooms, int n);
int				find_min(int **map, int cur, int n);
void			get_path(t_farm	*farm, t_path **paths);
void			init_map(int **map, int n, int start);
void			fill_map(t_farm *farm, int cur, int prev, int weight);
t_path			*find_paths(t_farm *farm);
void			read_input(char **res);
void			display_error(char **res, char *str);
int				check_n(char *str, char **res, int *f);
int				check_room(char *str, char **res, int *f);
int				check_link(char *str, char **res, int *f);
char			*ft_freejoin(char *s1, char *s2);
char			*add_nl(char *str);
long			ft_atol(char const *str);
void			init_links(t_farm *farm);
char			*ft_strndup(char const *s, size_t len);
t_farm			*parse_input(char **input);
int				has_end(t_farm *farm);
int				go_to_end(t_farm *farm, int room, int count);
int				find_start(t_room *rooms, int n);
void			parse_links(t_farm *farm, char **in);
int				find_room(t_room *rooms, int n, char *str);
int				are_valid_links(char *str, t_room *rooms, int q);
int				room_exist(t_room *rooms, int n, char *str);
int				check_comments(char *str);
void			parse_rooms(t_farm *farm, char **in);
void			parse_error(t_farm *farm, char **input);
void			free_farm(t_farm *farm);
int				check_room_names(t_room *rooms, int n);
int				check_room_coords(t_room *rooms, int n);
int				count_rooms(char *str, int points[2]);

#endif
