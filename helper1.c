/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:01:34 by ohesheli          #+#    #+#             */
/*   Updated: 2017/04/12 17:01:35 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_paths(t_path *paths)
{
	t_path	*crawler;

	while (paths)
	{
		crawler = paths;
		paths = paths->next;
		free(crawler->path);
		free(crawler->ants);
		free(crawler);
	}
}

void	free_input(char **input)
{
	free(input[0]);
	free(input[1]);
	free(input[2]);
	free(input);
}

int		find_min(int **map, int cur, int n)
{
	int		i;
	int		min;

	i = 0;
	min = n;
	while (i < n)
	{
		if (map[cur][i] < min)
			min = map[cur][i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (map[cur][i] == min)
			return (i);
		i++;
	}
	return (min);
}

int		find_start(t_room *rooms, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (rooms[i].start)
			return (i);
		i++;
	}
	return (-1);
}

int		find_end(t_room *rooms, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (rooms[i].end)
			return (i);
		i++;
	}
	return (-1);
}
