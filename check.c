/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:49:53 by ohesheli          #+#    #+#             */
/*   Updated: 2017/04/12 16:49:54 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		are_valid_links(char *str, t_room *rooms, int q)
{
	size_t		n;

	while (*str)
	{
		n = ft_strchr(str, '-') - str;
		if (!room_exist(rooms, q, ft_strndup(str, n)))
			return (0);
		if (ft_strnequ(&(str[n + 1]), str, ft_strchr(str, '\n') - str - n - 1))
			return (0);
		str = ft_strchr(str, '-') + 1;
		n = ft_strchr(str, '\n') - str;
		if (!room_exist(rooms, q, ft_strndup(str, n)))
			return (0);
		str = ft_strchr(str, '\n') + 1;
	}
	return (1);
}

int		room_exist(t_room *rooms, int n, char *str)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (ft_strequ(rooms[i].name, str))
		{
			free(str);
			return (1);
		}
		i++;
	}
	free(str);
	return (0);
}

int		check_comments(char *str)
{
	int		i;
	int		start;
	int		end;

	i = -1;
	start = 0;
	end = 0;
	while (str[++i])
	{
		if (ft_strnequ(&(str[i]), "##start\n", 8) && str[i + 8])
		{
			if (ft_strnequ(&(str[i + 8]), "##end\n", 6))
				return (1);
			start++;
		}
		if (ft_strnequ(&(str[i]), "##end\n", 6) && str[i + 6])
		{
			if (ft_strnequ(&(str[i + 6]), "##start\n", 8))
				return (1);
			end++;
		}
		while (str[i] != '\n')
			i++;
	}
	return ((start == 1 && end == 1) ? 0 : 1);
}

int		check_room_names(t_room *rooms, int n)
{
	int		i;
	int		j;
	char	*name;

	i = 0;
	while (i < n)
	{
		name = rooms[i].name;
		j = i + 1;
		while (j < n)
		{
			if (ft_strequ(name, rooms[j].name))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_room_coords(t_room *rooms, int n)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	while (i < n)
	{
		x = rooms[i].x;
		y = rooms[i].y;
		j = i + 1;
		while (j < n)
		{
			if (x == rooms[j].x && y == rooms[j].y)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
