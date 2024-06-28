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

int	calc_height_minimap(char **mini_map)
{
	int	y;

	y = 0;
	while (mini_map[y])
		y++;
	return (y);
}

void	check_char_mm(char **mm_array, t_cub3d *cub3d, \
		int y)
{
	int	x;

	x = 0;
	while (x < 5)
	{
		if ((int)cub3d->player.pos.y - 2 + y >= 0 && \
		(int)cub3d->player.pos.y - 2 + y < cub3d->map->length_y && \
		(int)cub3d->player.pos.x - 2 + x >= 0 && \
		(int)cub3d->player.pos.x - 2 + x < \
		(int)ft_strlen(cub3d->map->content[(int)cub3d->player.pos.y]))
		{
			//check of we op die -2 mogen indexen
			if (cub3d->minimap->og_map[(int)cub3d->player.pos.y - 2 + y] \
			[(int)cub3d->player.pos.x - 2 + x] == '1')
				mm_array[y][x] = '1';
			else if (cub3d->minimap->og_map[(int)cub3d->player.pos.y - 2 + y] \
				[(int)cub3d->player.pos.x - 2 + x] == 'P')
				mm_array[y][x] = 'P';
			else
				mm_array[y][x] = '0';
		}
		else
			mm_array[y][x] = '#';
		x++;
	}
}

char	**setup_minimap_arr(void)
{
	int		i;
	char	**mm_array;

	i = 0;
	mm_array = ft_calloc(6, sizeof(char *));
	if (!mm_array)
	{
		print_error(get_error_name(ERROR_ALLOCATION));
		return (NULL);
	}
	while (i < 5)
	{
		mm_array[i] = ft_calloc(6, sizeof(char));
		if (!mm_array[i])
		{
			print_error(get_error_name(ERROR_ALLOCATION));
			return (NULL);
		}
		i++;
	}
	mm_array[5] = NULL;
	return (mm_array);
}
