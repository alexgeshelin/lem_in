/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:43:16 by ohesheli          #+#    #+#             */
/*   Updated: 2017/04/12 16:43:18 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_input(char **res)
{
	char	*str;
	int		func;
	int		(*check_line[3])(char*, char**, int*);

	check_line[0] = &check_n;
	check_line[1] = &check_room;
	check_line[2] = &check_link;
	func = 0;
	str = NULL;
	while (get_next_line(0, &str))
	{
		if ((*check_line[func])(str, res, &func))
			display_error(res, str);
	}
	if (!res[0] || !res[1] || !res[2])
		display_error(res, NULL);
}

int		check_n(char *str, char **res, int *f)
{
	int		i;

	i = 0;
	if (!str || *str == 0)
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (1);
	}
	res[0] = str;
	*f = *f + 1;
	return (0);
}

int		check_room(char *str, char **res, int *f)
{
	int		i;
	int		ch;

	ch = 0;
	i = 0;
	if (str[0] != '#')
	{
		if (str[0] == 0 || str[0] == ' ' || str[0] == 'L')
			return (check_link(str, res, f));
		while (str[i] != 0 && str[i] != ' ')
			i++;
		if (str[i++] != ' ' && !ft_isdigit(str[i]))
			return (check_link(str, res, f));
		while (str[i])
		{
			if (!ft_isdigit(str[i]) && str[i] != ' ' && ++i)
				return (check_link(str, res, f));
			else if (str[i++] == ' ' && ++ch && ch != 1)
				return (check_link(str, res, f));
		}
		if (ch == 0)
			return (1);
	}
	res[1] = ft_freejoin(res[1], add_nl(str));
	return (0);
}

char	*add_nl(char *str)
{
	char	*res;

	res = ft_strjoin(str, "\n");
	free(str);
	return (res);
}

int		check_link(char *str, char **res, int *f)
{
	int		i;
	int		ch;

	i = 0;
	ch = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
		{
			if (str[i] == '-' && ch == 0 && ft_isalnum(str[i + 1]))
				ch = 1;
			else
				return (1);
		}
		i++;
	}
	if (ch == 0)
		return (1);
	*f = 2;
	res[2] = ft_freejoin(res[2], add_nl(str));
	return (0);
}
