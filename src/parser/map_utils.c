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
