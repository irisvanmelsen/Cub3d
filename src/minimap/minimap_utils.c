/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 17:52:33 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/06/06 17:52:33 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	draw_mm(char **mm_array, t_minimap *minimap)
{
	int			x;
	int			y;

	y = 0;
	while (mm_array[y])
	{
		x = 0;
		while (mm_array[y][x])
		{
			minimap->colour = 0;
			fill_colours(mm_array, minimap, y, x);
			fill_the_image(minimap, x, y);
			x++;
		}
		y++;
	}
}
