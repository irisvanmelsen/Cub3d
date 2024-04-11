/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:04:45 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/04/11 21:26:57 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	game_setup(t_cub3d *cub3d)
{
	mlx_image_setup(cub3d);
	init_raycast_data(cub3d->raycast, cub3d);
	raycaster(cub3d->raycast);
	start_minimap(cub3d);
	mlx_loop_hook(cub3d->mlx, cub3d_loop ,(void *)cub3d);
	// mlx_loop_hook(cub3d->mlx, change_dir, &cub3d->player);
	mlx_loop(cub3d->mlx);
	// mlx_set_mouse_pos(game->mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	// mlx_cursor_hook(cub3d->mlx, (mlx_cursorfunc)mouse_move, (void *)cub3d);
	// mlx_key_hook(cub3d->mlx, (mlx_keyfunc)cub3d_loop, (void *)cub3d);
	mlx_terminate(cub3d->mlx);
}

int	mlx_image_setup(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!cub3d->mlx)
		print_error(get_error_name(ERROR_MLX)); //clean exit?
	cub3d->background = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (!cub3d->background)
		return (print_error(get_error_name(ERROR_IMAGE)));
	cub3d->wall = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (!cub3d->wall)
		return (print_error(get_error_name(ERROR_IMAGE)));
	if (mlx_image_to_window(cub3d->mlx, cub3d->background, 0, 0) == -1)
		print_error(get_error_name(ERROR_IMAGE));
	if (mlx_image_to_window(cub3d->mlx, cub3d->wall, 0, 0) == -1)
		print_error(get_error_name(ERROR_IMAGE));
	cub3d_memset(cub3d->background->pixels, 0xffff0000, HALF_SCREENSIZE); //ask why ft_memset doesnt work
	cub3d_memset(&cub3d->background->pixels[HALF_SCREENSIZE * 4], 0xff0000ff, HALF_SCREENSIZE);
	return (1);
}


void	cub3d_memset(void *b, int colour, size_t len) // why ft_memset doesnt work
{
	size_t	i;
	int		*img;

	img = b;
	i = 0;
	while (i < len)
	{
		img[i] = colour;
		i++;
	}
}
