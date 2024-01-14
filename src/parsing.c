/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:58:27 by iris              #+#    #+#             */
/*   Updated: 2024/01/15 00:41:01 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parsing(int argc, char **argv)
{
	int		fd;
	t_map	map;

	fd = is_input_correct(argc, argv[1]);
	map.content = read_map(fd);
	if (!map.content)
		return (-1);
	int	i = 0;
	while (map.content[i])
	{
		printf("%s\n", map.content[i]);
		i++;
	}
	if (!has_map_errors(&map))
	{
		free_map_2d(map.content);
		return (-1);
	}
	if (!parse_elements_in_map(map.content))
		return (-1);
	return (1);
}


int	is_input_correct(int argc, char *map)
{
	int	fd;

	if (argc != 2)
	{
		printf("Wrong Amount of Arguments! Please enter: executable + map.\n");
		exit (EXIT_FAILURE);
	}
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		printf("No File Found! Please enter an existing file.\n");
		exit (EXIT_FAILURE);
	}
	if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4))
	{
		printf("Incorrect File! Please enter correct file type.\n");
		exit (EXIT_FAILURE);
	}
	return (fd);
}
