/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:53:19 by ohesheli          #+#    #+#             */
/*   Updated: 2017/04/12 16:53:20 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*find_paths(t_farm *farm)
{
	int		i;
	int		start;
	t_path	*paths;

	i = 0;
	paths = NULL;
	farm->map = (int**)malloc(sizeof(int*) * farm->n);
	while (i < farm->n)
		farm->map[i++] = (int*)malloc(sizeof(int) * farm->n);
	start = find_start(farm->rooms, farm->n);
	while (has_end(farm))
	{
		i = 0;
		init_map(farm->map, farm->n, start);
		while (i < farm->n)
		{
			if (farm->links[start][i])
				fill_map(farm, i, start, 1);
			i++;
		}
		get_path(farm, &paths);
	}
	return (paths);
}

void	get_path(t_farm *farm, t_path **paths)
{
	t_path	*path;
	int		i;
	int		cur;
	int		min;

	path = (t_path*)malloc(sizeof(t_path));
	cur = find_end(farm->rooms, farm->n);
	min = find_min(farm->map, cur, farm->n);
	path->l = farm->map[cur][min] + 1;
	path->path = (int*)malloc(sizeof(int) * path->l);
	path->ants = (long*)malloc(sizeof(long) * path->l);
	path->next = NULL;
	i = path->l;
	path->path[--i] = cur;
	path->ants[i] = 0;
	path->path[--i] = min;
	while (!(path->ants[i] = 0) && i)
	{
		cur = min;
		min = find_min(farm->map, cur, farm->n);
		path->path[--i] = min;
	}
	fill_list(paths, path);
	delete_links(farm, path);
}

void	delete_links(t_farm *farm, t_path *path)
{
	int		i;
	int		j;

	i = 1;
	if (path->l == 2)
		farm->links[path->path[0]][path->path[1]] = 0;
	while (i < path->l - 1)
	{
		j = 0;
		while (j < farm->n)
		{
			farm->links[path->path[i]][j] = 0;
			farm->links[j][path->path[i]] = 0;
			j++;
		}
		i++;
	}
}

void	fill_map(t_farm *farm, int cur, int prev, int weight)
{
	int		i;

	if (weight < farm->map[cur][prev] && weight < farm->n)
	{
		i = 0;
		farm->map[cur][prev] = weight;
		while (i < farm->n)
		{
			if (i != prev && farm->links[cur][i])
				fill_map(farm, i, cur, weight + 1);
			i++;
		}
	}
}

void	init_map(int **map, int n, int start)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		if (i != start)
		{
			while (j < n)
				map[i][j++] = n;
		}
		else
		{
			while (j < n)
				map[i][j++] = 0;
		}
		i++;
	}
}
