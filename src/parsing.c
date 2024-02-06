/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 14:58:27 by iris          #+#    #+#                 */
/*   Updated: 2024/01/26 17:15:09 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(int argc, char **argv, t_map *map)
{
	int		fd;
	int		i;

	fd = is_input_correct(argc, argv[1]);
	map->content = read_map(fd);
	if (!map->content)
		return (0);
	i = 0;
	if (!has_map_errors(map))
	{
		free_map_2d(map->content);
		return (0);
	}
	print_2d_charray(map->content);
	return (1);
}

//  !parse_elements_in_map(map->content))

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
