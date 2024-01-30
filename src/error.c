/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 22:12:03 by iris          #+#    #+#                 */
/*   Updated: 2024/01/26 17:40:34 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	has_map_errors(t_map *map)
{
	char	**dup_map;

	map_init(map);
	if (!check_characters(map))
	{
		printf("Invalid Amount of Characters!\n");
		return (-1);
	}
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
