/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/01 23:37:15 by iris          #+#    #+#                 */
/*   Updated: 2024/02/07 13:22:40 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**create_dup_map(t_map *map)
{
	int	i;

	i = 0;
	map->dup_content = (char **)ft_calloc((map->length_y + 1), sizeof(char *));
	if (!map->dup_content)
		return (0);
	while (i < map->length_y)
	{
		map->dup_content[i] = ft_strdup(map->file_content[i]);
		if (!map->dup_content[i])
		{
			free_map_2d(map->dup_content);
			return (NULL);
		}
		i++;
	}
	return (map->dup_content);
}

int	check_map_after_ff(char **map_after_ff)
{
	int	x;
	int	y;

	y = 0;
	while (map_after_ff[y])
	{
		x = 0;
		while (map_after_ff[y][x])
		{
			if (map_after_ff[y][x] != '1' && map_after_ff[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
