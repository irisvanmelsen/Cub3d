/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/01 13:22:54 by ivan-mel      #+#    #+#                 */
/*   Updated: 2024/03/19 19:11:20 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

	void	init_minimap(t_cub3d *cub3d)
	{
		cub3d->minimap->cub3d = cub3d;
		cub3d->minimap->mlx = cub3d->mlx;
		cub3d->minimap->scaler = MINI_WIDTH / 8;
		cub3d->minimap->og_map = cub3d->map->content;
	}

int	calc_height_minimap(char **mini_map)
{
	int y;

	y = 0;
	while (mini_map[y])
		y++;
	return (y);
}

char	**compare_maps(char **mm_array, char **mini_map, int player_x, int player_y)
{
	int	x;
	int	y;
	int	map_height;
	int	mm_height;

	y = 0;
	map_height = calc_height_minimap(mini_map);
	if (map_height < 5)
	{
		if (map_height == 4)
			mm_height = 4;
		else
			mm_height = map_height + 1;
	}
	else
		mm_height = 5;
	while (y < mm_height)
	{
		x = 0;
		while (x < 5)
		{
			if (player_y - 2 + y >= 0 && player_y - 2 + y  < MINI_HEIGHT && \
				player_x - 2 + x >= 0 && player_x - 2 + x <MINI_WIDTH)
			{
				if (mini_map[player_y - 2 + y][player_x - 2 + x] == '1')
					mm_array[y][x] = '1';
				else if (mini_map[player_y - 2 + y][player_x - 2 + x] == 'P')
					mm_array[y][x] = 'P';
				else
					mm_array[y][x] = '0';
			}
			else
				mm_array[y][x] = '#';
			x++;
		}
		y++;
	}
	mm_array[2][2] = 'P';
	return (mm_array);
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

	void	fill_the_image(t_minimap *minimap, int x, int y, uint32_t colour)
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
				mlx_put_pixel(minimap->image, x, y, colour);
				y++;
			}
			x++;
		}
	}

	void	fill_wall_backgr(char **mm_array, t_minimap *minimap)
	{
		int			x;
		int			y;
		uint32_t	colour;

		y = 0;
		while (mm_array[y])
		{
			x = 0;
			while (mm_array[y][x])
			{
				colour = 0;
				if (mm_array[y][x] == '#')
					colour = get_rgba(0, 0, 0, 0);
				else if (mm_array[y][x] == '0')
					colour = get_rgba(LAVENDER);
				else if (mm_array[y][x] == '1')
					colour = get_rgba(LIGHTPINK);
				else if (mm_array[y][x] == 'P')
					colour = get_rgba(LIGHTCORAL);
				fill_the_image(minimap, x, y, colour);
				x++;
			}
			y++;
		}
		mlx_put_string(minimap->mlx, "      M I N I M A P : ", 1, 2);
		if (mlx_image_to_window(minimap->mlx, minimap->image, minimap->scaler / 2, minimap->scaler / 2) == -1)
			print_error(get_error_name(ERROR_IMAGE));
		mlx_put_string(minimap->mlx, " P ", 120, 125);
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
				mlx_put_pixel(minimap->border, x, y, get_rgba(MISTYROSE));
				x++;
			}
			y++;
		}
		if (mlx_image_to_window(minimap->mlx, minimap->border, 0, 0) == -1)
			if (!minimap->border)
				print_error(get_error_name(ERROR_IMAGE));
	}

	bool	start_minimap(t_cub3d *cub3d)
	{
		char	**mm_array;

		cub3d->minimap = ft_calloc(1, sizeof(t_minimap));
		if (!cub3d->minimap)
			print_error(get_error_name(ERROR_ALLOCATION));
		init_minimap(cub3d);
		if (!cub3d->minimap->image)
		{
			cub3d->minimap->image = mlx_new_image(cub3d->minimap->mlx, MINI_WIDTH, MINI_HEIGHT);
			if (!cub3d->minimap->image)
				return (print_error(get_error_name(ERROR_IMAGE)));
		}
		if (!cub3d->minimap->border)
			setup_border(cub3d->minimap);
		mm_array = setup_minimap_arr();
		mm_array = compare_maps(mm_array, cub3d->minimap->og_map, cub3d->map->player_x, cub3d->map->player_y);
		fill_wall_backgr(mm_array, cub3d->minimap);
		free_map_2d(mm_array);
		return (true);
	}
