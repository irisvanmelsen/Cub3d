/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 14:58:27 by iris          #+#    #+#                 */
/*   Updated: 2024/02/08 15:36:09 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	parsing(int argc, char **argv, t_cub3d *cub3d, t_map *map)
{
	int		fd;
	int		i;

	fd = is_input_correct(argc, argv[1]);
	if (!map_init(map, fd))
		return (false);
	i = 0;
	// print_2d_charray(map->file_content);
	if (!has_map_errors(map) || !parse_elements_in_file(cub3d, map->file_content))
	{
		free_map_2d(map->file_content);
		return (false);
	}
	return (true);
}

bool	has_map_errors(t_map *map)
{
	int	ret;

	ret = true;
	if (!only_one_player_symbol(map))
		print_error(get_error_name(ERROR_CHARACTER));

	if (!find_player_pos(map) || floodfill(map, map->dup_content, map->player_y, map->player_x))
	{
		printf("Not a Valid Map!\n");
		ret = false;
	}
	free_map_2d(map->dup_content);
	return (ret);
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
