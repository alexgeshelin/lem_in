/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:57:44 by ohesheli          #+#    #+#             */
/*   Updated: 2017/04/12 16:57:45 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	go_ants_go(t_farm *farm, t_path *paths)
{
	int		end;

	end = find_end(farm->rooms, farm->n);
	while ((farm->rooms[end]).ant != farm->ants)
	{
		move_ants(farm, paths);
		enter_ants(farm, paths);
		ft_printf("\n");
	}
}

void	move_ants(t_farm *farm, t_path *paths)
{
	int		i;
	int		end;

	end = find_end(farm->rooms, farm->n);
	while (paths)
	{
		i = paths->l - 1;
		if (paths->ants[--i])
		{
			(farm->rooms[end]).ant++;
			ft_printf("L%ld-%s ", paths->ants[i], (farm->rooms[end]).name);
			paths->ants[i] = 0;
		}
		while (i)
		{
			if (paths->ants[--i])
			{
				ft_printf("L%ld-%s ", paths->ants[i],\
				(farm->rooms[paths->path[i + 1]]).name);
				paths->ants[i + 1] = paths->ants[i];
				paths->ants[i] = 0;
			}
		}
		paths = paths->next;
	}
}

void	enter_ants(t_farm *farm, t_path *paths)
{
	int			l;
	static int	ant = 1;

	l = paths->l;
	while (paths && ant <= farm->ants)
	{
		if (paths->l - l >= farm->ants)
			break ;
		ft_printf("L%ld-%s ", ant, (farm->rooms[paths->path[1]]).name);
		if (farm->rooms[paths->path[1]].end)
			farm->rooms[paths->path[1]].ant++;
		paths->ants[1] = ant;
		ant++;
		paths = paths->next;
	}
}

void	fill_list(t_path **paths, t_path *path)
{
	t_path	*crawler;

	if (*paths == NULL)
		*paths = path;
	else
	{
		crawler = *paths;
		while (crawler->next)
			crawler = crawler->next;
		crawler->next = path;
	}
}

void	display_error(char **res, char *str)
{
	ft_putstr("ERROR\n");
	free(str);
	free(res[0]);
	free(res[1]);
	free(res[2]);
	free(res);
	exit(0);
}
