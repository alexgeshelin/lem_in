/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 12:49:54 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/20 12:56:59 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	char	**input;
	t_farm	*farm;
	t_path	*paths;

	input = (char**)malloc((sizeof(char*) * 3));
	input[0] = NULL;
	input[1] = NULL;
	input[2] = NULL;
	read_input(input);
	farm = parse_input(input);
	paths = find_paths(farm);
	ft_printf("%s\n%s%s\n", input[0], input[1], input[2]);
	free_input(input);
	go_ants_go(farm, paths);
	free_farm(farm);
	free_paths(paths);
}
