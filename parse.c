/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:46:32 by ohesheli          #+#    #+#             */
/*   Updated: 2017/04/12 16:46:33 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_farm	*parse_input(char **input)
{
	t_farm	*farm;
	int		rooms;
	int		points[2];

	if ((rooms = count_rooms(input[1], points)) < 2 || check_comments(input[1]))
		display_error(input, NULL);
	farm = (t_farm*)malloc(sizeof(t_farm));
	farm->ants = ft_atol(input[0]);
	farm->rooms = (t_room*)malloc(sizeof(t_room) * (rooms + 1));
	farm->n = rooms;
	farm->links = NULL;
	farm->map = NULL;
	parse_rooms(farm, input);
	(farm->rooms[points[0]]).start = 1;
	(farm->rooms[points[1]]).end = 1;
	init_links(farm);
	parse_links(farm, input);
	if (farm->ants == 0 || !has_end(farm))
		parse_error(farm, input);
	return (farm);
}

void	parse_links(t_farm *farm, char **in)
{
	char	*str;
	int		room1;
	int		room2;

	str = in[2];
	if (!are_valid_links(in[2], farm->rooms, farm->n))
		parse_error(farm, in);
	while (*str)
	{
		room1 = find_room(farm->rooms, farm->n, ft_strndup(str,\
		ft_strchr(str, '-') - str));
		str = ft_strchr(str, '-') + 1;
		room2 = find_room(farm->rooms, farm->n, ft_strndup(str,\
		ft_strchr(str, '\n') - str));
		farm->links[room1][room2] = 1;
		farm->links[room2][room1] = 1;
		str = ft_strchr(str, '\n') + 1;
	}
}

void	parse_rooms(t_farm *farm, char **in)
{
	char	*str;
	int		i;
	t_room	*rooms;

	str = in[1];
	i = 0;
	rooms = farm->rooms;
	while (i != farm->n)
	{
		while (*str == '#')
			str = ft_strchr(str, '\n') + 1;
		rooms[i].name = ft_strnew(ft_strchr(str, ' ') - str);
		ft_strncpy(rooms[i].name, str, ft_strchr(str, ' ') - str);
		str = ft_strchr(str, ' ') + 1;
		rooms[i].x = ft_atoi(str);
		str = ft_strchr(str, ' ') + 1;
		rooms[i].y = ft_atoi(str++);
		str = ft_strchr(str, '\n') + 1;
		rooms[i].start = 0;
		rooms[i].ant = 0;
		rooms[i++].end = 0;
	}
	if (check_room_names(rooms, farm->n) || check_room_coords(rooms, farm->n))
		parse_error(farm, in);
}

void	init_links(t_farm *farm)
{
	int i;
	int j;

	i = 0;
	farm->links = (int**)malloc(sizeof(int*) * farm->n);
	while (i < farm->n)
	{
		j = 0;
		farm->links[i] = (int*)malloc(sizeof(int) * farm->n);
		while (j < farm->n)
			farm->links[i][j++] = 0;
		i++;
	}
}

void	parse_error(t_farm *farm, char **input)
{
	free_farm(farm);
	free(input[0]);
	free(input[1]);
	free(input[2]);
	free(input);
	ft_putstr("ERROR\n");
	exit(0);
}
