/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:12:03 by iris              #+#    #+#             */
/*   Updated: 2024/01/15 00:39:09 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_errors(t_map *map)
{
	if (!check_sides_wall(map))
	{
		printf("Invalid Wall! Map must be surrounded by 1 characters.\n");
		return (0);
	}
	if (!check_first_last_walls(map))
	{
		printf("Invalid Wall! Map must be surrounded by 1 characters.\n");
		return (0);
	}
	if (!check_characters(map))
	{
		printf("Invalid Amount of Characters!\n");
		return (0);
	}
	return (1);
}

int	has_map_errors(t_map *map)
{
	char	**map_after_ff;
	char	**dup_map;

	map_init(map);
	if (!check_errors(map))
		return (-1);
	dup_map = create_dup_map(map);
	map_after_ff = floodfill(dup_map, map->player_y, map->player_x);
	if (!check_map_after_ff(map_after_ff))
	{
		free_map_2d(map_after_ff);
		printf("Invalid Path! Please enter a Valid Map.\n");
		return (-1);
	}
	free_map_2d(dup_map);
	return (1);
}
