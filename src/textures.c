/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: iris <iris@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 20:45:45 by ivan-mel      #+#    #+#                 */
/*   Updated: 2024/04/12 22:13:17 by iris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	texture_colours(t_textures *texture, double x, double y)
{
	int		int_x;
	int		int_y;
	int		index;
	uint8_t	*pixels;

	int_x = (int)x;
	int_y = (int)y;
	index = (int_y * texture->used_tex->width + int_x) * \
			texture->used_tex->bytes_per_pixel;
	pixels = texture->used_tex->pixels;
	texture->r = pixels[index];
	texture->g = pixels[index + 1];
	texture->b = pixels[index + 2];
	texture->a = pixels[index + 3];
	return (get_rgba(texture->r, texture->g, texture->b, texture->a));
}

// void	load_textures_in(t_cub3d *cub3d)
// {
// 	cub3d->textures.north_text = mlx_load_png(cub3d->textures.north);
// 	if (!cub3d->textures.north_text)
// 		print_error(get_error_name(ERROR_LOAD));
// 	cub3d->textures.south_text = mlx_load_png(cub3d->textures.south);
// 	if (!cub3d->textures.south_text)
// 		print_error(get_error_name(ERROR_LOAD));
// 	cub3d->textures.west_text = mlx_load_png(cub3d->textures.west);
// 	if (!cub3d->textures.west_text)
// 		print_error(get_error_name(ERROR_LOAD));
// 	cub3d->textures.east_text = mlx_load_png(cub3d->textures.east);
// 	if (!cub3d->textures.east_text)
// 		print_error(get_error_name(ERROR_LOAD));
// }
