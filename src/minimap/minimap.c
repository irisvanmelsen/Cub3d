/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:22:54 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/03/12 13:59:15 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_minimap(t_cub3d *cub3d)
{
	cub3d->minimap->cub3d = cub3d;
	cub3d->minimap->mlx = cub3d->mlx;
	cub3d->minimap->scaler = MINI_WIDTH / 6;
	cub3d->minimap->og_map = cub3d->map->file_content;
}

int		max_y_calc(char **mini_map)
{
	int	i;

	i = 0;
	while (mini_map[i])
		i++;
	return (i);
}

bool	boundary_check(char **mini_map, int player_y, int player_x, int y, int x)
{
	if (player_y + y > max_y_calc(mini_map) - 1|| player_x + x > ft_strlen(mini_map[player_y]) - 1)
		return (false);
	if (player_y + y < -2 || player_x + x < -2)
		return (false);
	return (true);
}

// char	**compare_maps(char **mm_array, char **mini_map, int player_x, int player_y)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < 6)	
// 	{
// 		x = 0;
// 		while (x < 6)
// 		{
// 			if (boundary_check(mini_map, player_y, player_x, y, x) == true)
// 				mm_array[y][x] = '0';
// 			printf("goes bad here?\n");
// 			if (mini_map[player_y + y][player_x + x] == '0')
// 				mm_array[y][x] = '0';
// 			else if (mini_map[player_y + y][player_x + x] == '1')
// 				mm_array[y][x] = '1';
// 			else if (mini_map[player_y + y][player_x + x] == ' ')
// 				mm_array[y][x] = '1';
// 			x++;
// 		}
// 		y++;
// 	}
// 	mm_array[2][2] = 'P';
// 	return (mm_array);
// }

char	**compare_maps(char **mm_array, char **mini_map, int player_x, int player_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < 6)	
	{
		x = 0;
		while (x < 6)
		{
			if (boundary_check(mini_map, player_y, player_x, y, x) == true)
				mm_array[y][x] = '0';
			if (mini_map[player_y][player_x] == '0')
				mm_array[y][x] = '0';
			else if (mini_map[player_y + y][player_x + x] == '1')
				mm_array[y][x] = '1';
			else if (mini_map[player_y + y][player_x + x] == ' ')
				mm_array[y][x] = '1';
			x++;
		}
		y++;
	}
	mm_array[2][2] = 'P';
	return (mm_array);
}

char	**setup_minimap_arr(void)
{
	int	i;
	char **mm_array;

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
	mm_array[i] = NULL;
	return (mm_array);
}

void	fill_the_image(t_minimap *minimap, int x, int y, uint32_t colour)
{
	int	x_max;
	int	y_max;
	int	tmp;
	int	y_tmp;
	x_max = (x + 1) * minimap->scaler;
	y_max = (y + 1) * minimap->scaler;
	tmp = y * minimap->scaler;
	x = x * minimap->scaler;
	if (x_max > MINI_WIDTH)
		x_max = MINI_WIDTH;
	if (y_max > MINI_HEIGHT)
		y_max = MINI_HEIGHT;
	while (x < x_max)
	{
		y_tmp = tmp;
		while (y_tmp < y_max)
		{
			mlx_put_pixel(minimap->image, x, y_tmp, colour);
		}
		x++;
	}
}

void	fill_wall_backgr(char **mm_array, t_minimap *minimap, t_cub3d *cub3d)
{
	if (mlx_image_to_window(cub3d->mlx, cub3d->background, 0, 0) == -1)
		print_error(get_error_name(ERROR_IMAGE));
	if (mlx_image_to_window(cub3d->mlx, cub3d->wall, 0, 0) == -1)
		print_error(get_error_name(ERROR_IMAGE));
	int			x;
	int			y;
	uint32_t	colour;

	y = 0;
	while (mm_array[y])
	{
		x = 0;
		while (mm_array[x][y])
		{
			colour = 0;
			if (mm_array[y][x] == '-')
				colour = get_rgba(0, 0, 0, 0);
			else if (mm_array[y][x] == '0')
				colour = get_rgba(0, 255, 2555, 0);
			else if (mm_array[y][x] == '1')
				colour = get_rgba(0, 255, 255, 255);
			else if (mm_array[y][x] == 'P')
				colour = get_rgba(255, 0, 0, 0);
			fill_the_image(minimap, x, y, colour);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(minimap->mlx, minimap->image, minimap->scaler, minimap->scaler) == -1)
		print_error(get_error_name(ERROR_IMAGE));
}

bool	start_minimap(t_cub3d *cub3d)
{
	char	**mm_array;
	char	**mm_setup;

	printf("player_x: %d\n", cub3d->map->player_x);
	printf("player_y: %d\n", cub3d->map->player_y);
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
	mm_setup = setup_minimap_arr();
	int i = 0;

	while (mm_setup[i])
	{
		printf("mm_setup: %s", mm_setup[i]);
		i++;
	}
	mm_array = compare_maps(mm_setup, cub3d->minimap->og_map, cub3d->map->player_x, cub3d->map->player_y);
	fill_wall_backgr(mm_array, cub3d->minimap, cub3d);
	free_map_2d(mm_setup);
	free_map_2d(mm_array);
	return (true);
}