/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_image.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: iris <iris@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/09 14:03:01 by ivan-mel      #+#    #+#                 */
/*   Updated: 2024/05/18 19:13:53 by iris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_the_image(t_minimap *minimap, int x, int y)
{
	int	x_max;
	int	y_max;
	int	tmp_y;

	x_max = (x + 1) * minimap->scaler;
	y_max = (y + 1) * minimap->scaler;
	tmp_y = y * minimap->scaler;
	x = x * minimap->scaler;
	if (x_max > MINI_WIDTH)
		x_max = MINI_WIDTH;
	if (y_max > MINI_HEIGHT)
		y_max = MINI_HEIGHT;
	while (x < x_max)
	{
		y = tmp_y;
		while (y < y_max)
		{
			mlx_put_pixel(minimap->image, x, y, minimap->colour);
			y++;
		}
		x++;
	}
}

void	fill_colours(char **mm_array, t_minimap *minimap, int y, int x)
{
	if (mm_array[y][x] == '#')
		minimap->colour = get_rgba(0, 0, 0, 0);
	else if (mm_array[y][x] == '0')
		minimap->colour = (uint32_t)EUCALYPTUS;
	else if (mm_array[y][x] == '1')
		minimap->colour = (uint32_t)MINT;
	else if (mm_array[y][x] == 'P')
		minimap->colour = (uint32_t)PISTACHIO;
}

void	fill_wall_backgr(char **mm_array, t_minimap *minimap)
{
	draw_mm(mm_array, minimap);
	mlx_put_string(minimap->mlx, "      M I N I M A P : ", 1, 2);
	if (mlx_image_to_window(minimap->mlx, minimap->image, minimap->scaler / 2, \
		minimap->scaler / 2) == -1)
		print_error(get_error_name(ERROR_IMAGE));
	mlx_put_string(minimap->mlx, " P ", 120, 125);
	mlx_put_string(minimap->mlx, "N", 125, 30);
	mlx_put_string(minimap->mlx, "S", 125, 220);
	mlx_put_string(minimap->mlx, "E", 230, 130);
	mlx_put_string(minimap->mlx, "W", 30, 130);
}

void	setup_border(t_minimap *minimap)
{
	int	border_length;
	int	y;
	int	x;

	y = 0;
	border_length = minimap->scaler * 6;
	minimap->border = mlx_new_image(minimap->mlx, border_length, border_length);
	if (!minimap->border)
		print_error(get_error_name(ERROR_IMAGE));
	while (y < minimap->scaler * 6)
	{
		x = 0;
		while (x <= border_length)
		{
			mlx_put_pixel(minimap->border, x, y, (uint32_t)PISTACHIO);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(minimap->mlx, minimap->border, 0, 0) == -1)
		if (!minimap->border)
			print_error(get_error_name(ERROR_IMAGE));
}

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
