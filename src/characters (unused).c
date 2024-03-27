// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   characters.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/12/30 23:59:29 by iris              #+#    #+#             */
// /*   Updated: 2024/03/20 20:28:40 by iris             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "cub3d.h"



// int	check_characters(t_map *map)
// {
// 	int	x;
// 	int	y;
// 	int	player_count;
// 	char c;

// 	y = 0;
// 	player_count = 0;
// 	while (map->content[y])
// 	{
// 		x = 0;
// 		while (map->content[y][x])
// 		{
// 			c = map->content[y][x]
// 			if (c == 'N' || c == 'S' || c == 'E' c == 'W')
// 				player_count++;
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (player_count != 1)
// 		return (0);
// 	return (1);
// }

// int	check_sides_wall(t_map *map)
// {
// 	int	y;
// 	int	line_length;

// 	y = 0;
// 	while (map->content[y])
// 	{
// 		line_length = ft_strlen(map->content[y]);
// 		if (line_length > 0 && (map->content[y][0] != '1' \
// 			&& map->content[y][0] != ' '))
// 			return (0);
// 		if (line_length > 0 && (map->content[y][line_length - 1] != '1' \
// 			&& map->content[y][line_length - 1] != ' '))
// 			return (0);
// 		y++;
// 	}
// 	return (1);
// }

// // walls moeten ook gecheckt worden op 0 in de 'gaps'

// // while (map[x][y])
// // {
// // 	if (map[x][y] == ' ')
// // 	{
// // 		if map(x + 1) | -1 of y + 1 || -1 == ' ' || '1')
// // 	}
// // }

// int	check_first_last_walls(t_map *map)
// {
// 	int	x;

// 	x = 0;
// 	while (map->content[0][x])
// 	{
// 		if (map->content[0][x] != '1')
// 			return (1);
// 		x++;
// 	}
// 	x = 0;
// 	while (map->content[map->length_y - 1][x])
// 	{
// 		if (map->content[map->length_y - 1][x] != '1' &&
// 			map->content[map->length_y - 1][x] != ' ' )
// 			return (0);
// 		x++;
// 	}
// 	return (1);
// }
