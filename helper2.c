/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:03:45 by ohesheli          #+#    #+#             */
/*   Updated: 2017/04/12 17:03:46 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		has_end(t_farm *farm)
{
	int		start;

	start = find_start(farm->rooms, farm->n);
	return (go_to_end(farm, start, 0));
}

int		go_to_end(t_farm *farm, int room, int count)
{
	int		i;

	i = 0;
	if ((farm->rooms[room]).end == 1)
		return (1);
	if (count > farm->n)
		return (0);
	while (i < farm->n)
	{
		if (farm->links[room][i] == 1)
		{
			if (go_to_end(farm, i, count + 1))
				return (1);
		}
		i++;
	}
	return (0);
}

int		find_room(t_room *rooms, int n, char *str)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (ft_strequ(rooms[i].name, str))
		{
			free(str);
			return (i);
		}
		i++;
	}
	free(str);
	return (-1);
}

void	free_farm(t_farm *farm)
{
	int		i;

	i = 0;
	while (i < farm->n)
		free((farm->rooms[i++]).name);
	i = 0;
	while (farm->links && i < farm->n)
		free(farm->links[i++]);
	free(farm->links);
	i = 0;
	while (i < farm->n && farm->map)
		free(farm->map[i++]);
	free(farm->map);
	free(farm->rooms);
	free(farm);
}

int		count_rooms(char *str, int points[2])
{
	int		n;

	n = 0;
	while (*str)
	{
		if (*str && *str == '#')
		{
			if (ft_strnequ(str, "##start\n", 8))
				points[0] = n;
			if (ft_strnequ(str, "##end\n", 6))
				points[1] = n;
			n--;
		}
		str = ft_strchr(str, '\n') + 1;
		n++;
	}
	return (n);
}
