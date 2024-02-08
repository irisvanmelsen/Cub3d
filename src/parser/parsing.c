/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:58:27 by iris              #+#    #+#             */
/*   Updated: 2024/02/08 15:36:09 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parsing(int argc, char **argv, t_cub3d *cub3d, t_map *map)
{
	int		fd;
	int		i;

	fd = is_input_correct(argc, argv[1]);
	map->input_content = read_map(fd);
	if (!map->input_content)
		return (0);
	i = 0;
	while (map->input_content[i])
	{
		printf("%s\n", map->input_content[i]);
		i++;
	}
	if (!has_map_errors(map) || !parse_elements_in_map(cub3d, map->input_content))
	{
		free_map_2d(map->input_content);
		return (-1);
	}
	create_map(map);
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
