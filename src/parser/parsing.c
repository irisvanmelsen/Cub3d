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

int	parsing(int argc, char **argv, t_map *map, t_cub3d	*cub3d)
{
	int		fd;
	int		i;

	(void)cub3d;
	fd = is_input_correct(argc, argv[1]);
	map->content = read_map(fd);
	if (!map->content)
		return (0);
	i = 0;
	print_2d_charray(map->content);
	if (!has_map_errors(map))
	{
		free_map_2d(map->content);
		return (0);
	}
	return (1);
}
// !parse_elements_in_map(&cub3d, map->content) here till fixed

int	is_input_correct(int argc, char *map)
{
	int	fd;

	if (argc != 2)
		error_exit("Wrong Amount of Arguments! Please enter:\
		executable + map.\n", EXIT_FAILURE);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_exit("No File Found! Please enter an existing file.\n" ,\
		EXIT_FAILURE);
	if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4))
		error_exit("Incorrect File! Please enter correct file type.\n" ,\
		EXIT_FAILURE);
	return (fd);
}
