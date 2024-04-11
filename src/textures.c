/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:45:45 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/04/11 22:55:30 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	make_textures_images(t_cub3d *cub3d)
// {
// 	cub3d->textures.north_text_img = mlx_texture_to_image(cub3d->mlx, cub3d->textures.north);
// 	if (!cub3d->textures.north_text_img)
// 		print_error(get_error_name(ERROR_IMAGE));
// 	cub3d->textures.south_text_img = mlx_texture_to_image(cub3d->mlx, cub3d->textures.south);
// 	if (!cub3d->textures.south_text_img)
// 		print_error(get_error_name(ERROR_IMAGE));
// 	cub3d->textures.west_text_img = mlx_texture_to_image(cub3d->mlx, cub3d->textures.west);
// 	if (!cub3d->textures.west_text_img)
// 		print_error(get_error_name(ERROR_IMAGE));
// 	cub3d->textures.east_text_img = mlx_texture_to_image(cub3d->mlx, cub3d->textures.east);
// 	if (!cub3d->textures.east_text_img)
// 		print_error(get_error_name(ERROR_IMAGE));
// }

uint32_t texture_colours(t_textures *texture, double x, double y, int colour)
{
	int	int_x;
	int	int_y;
	int	index;
	uint8_t *pixels;

	x = (int)x + colour;
	y = (int)y;
    index = (int_y * texture->used_tex.width + int_x) * texture->used_tex.bytes_per_pixel;
    pixels = texture->used_tex.pixels;

    // Extract RGBA components directly
    texture->r = pixels[index];
    texture->g = pixels[index + 1];
    texture->b = pixels[index + 2];
    texture->a = pixels[index + 3];

    return get_rgba(texture->r, texture->g, texture->b, texture->a);
}

void	load_textures_in(t_cub3d *cub3d)
{
	cub3d->textures.north_text = mlx_load_png(cub3d->textures.north);
	if (!cub3d->textures.north_text)
		print_error(get_error_name(ERROR_LOAD));
	cub3d->textures.south_text = mlx_load_png(cub3d->textures.south);
	if (!cub3d->textures.south_text)
		print_error(get_error_name(ERROR_LOAD));
	cub3d->textures.west_text = mlx_load_png(cub3d->textures.west);
	if (!cub3d->textures.west_text)
		print_error(get_error_name(ERROR_LOAD));
	cub3d->textures.east_text = mlx_load_png(cub3d->textures.east);
	if (!cub3d->textures.east_text)
		print_error(get_error_name(ERROR_LOAD));
}