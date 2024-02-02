/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 22:12:03 by iris          #+#    #+#                 */
/*   Updated: 2024/02/02 15:03:41 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	has_map_errors(t_map *map)
{
	char	**dup_map;

	map_init(map);
	if (!check_characters(map))
		print_error(get_error_name(ERROR_CHARACTER));
	dup_map = create_dup_map(map);
	if (!dup_map)
		return (-1);
	if (!find_player_pos(map) || floodfill(map, dup_map, map->player_y, map->player_x))
	{
		printf("Not a Valid Map!\n");
		free_map_2d(dup_map);
		return(-1);
	}
	free_map_2d(dup_map);
	return (1);
}

char	*get_error_name(t_error error)
{
	static char	*str[] = {\
		[ERROR_CHARACTER] = "Invalid Amount of Positions!\n", \
		[ERROR_MLX] = "MLX Initialisation has Failed!\n", \
		[ERROR_IMAGE] = "MLX Image Initialisation has Failed!\n"};

	return (str[error]);
}

int	print_error(char *str)
{
	write (STDERR_FILENO, str, ft_strlen(str));
	return (EXIT_FAILURE);
}
