/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 14:58:27 by iris          #+#    #+#                 */
/*   Updated: 2024/05/09 16:45:46 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	is_input_correct(int argc, char *map);
static char	**read_file(int fd);

bool	parsing(int argc, char **argv, t_cub3d *cub3d, t_map *map)
{
	int	fd;
	int	map_start_index;

	ft_bzero((void *)map, sizeof(t_map));
	fd = is_input_correct(argc, argv[1]);
	if (!fd)
		return (print_error("\nOpen failed"));
	map->file_content = read_file(fd);
	if (!map->file_content)
		return (print_error("\nconversion from file to array failed"));
	map_start_index = parse_and_load_textures(cub3d, map->file_content);
	if (!map_start_index)
		return (print_error("\nCan't load elements\n"));
	if (!map_init(map, map_start_index))
		return (print_error("\nMap error"));
	return (true);
}

static int	is_input_correct(int argc, char *map)
{
	int	fd;

	if (argc != 2)
		return (print_error("Wrong Amount of Arguments! \
		Please enter: executable + map.\n"));
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (print_error("No File Found! Please enter an existing file.\n"));
	if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4))
		return (print_error("Incorrect File! \
		Please enter correct file type.\n"));
	return (fd);
}

static char	**read_file(int fd)
{
	char	*map_line;
	char	*line;
	char	**result;

	line = NULL;
	map_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (free_line_if_empty(line))
			continue ;
		map_line = ft_strjoin_free(map_line, line);
		if (!map_line)
			return (NULL);
	}
	if (!map_line)
		return (NULL);
	result = ft_split(map_line, '\n');
	free(map_line);
	if (!result)
		return (NULL);
	return (result);
}
