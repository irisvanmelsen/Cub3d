/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:45:45 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/04/09 21:19:05 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_textures_images(t_cub3d *cub3d)
{
	cub3d->textures.north_text_img = mlx_texture_to_image(cub3d->mlx, cub3d->textures.north);
	if (!cub3d->textures.north_text_img)
		print_error(get_error_name(ERROR_IMAGE));
	cub3d->textures.south_text_img = mlx_texture_to_image(cub3d->mlx, cub3d->textures.south);
	if (!cub3d->textures.south_text_img)
		print_error(get_error_name(ERROR_IMAGE));
	cub3d->textures.west_text_img = mlx_texture_to_image(cub3d->mlx, cub3d->textures.west);
	if (!cub3d->textures.west_text_img)
		print_error(get_error_name(ERROR_IMAGE));
	cub3d->textures.east_text_img = mlx_texture_to_image(cub3d->mlx, cub3d->textures.east);
	if (!cub3d->textures.east_text_img)
		print_error(get_error_name(ERROR_IMAGE));
}

// void	load_textures_in(t_cub3d *cub3d)
// {
// 	cub3d->textures->north_text = mlx_load_png(cub3d->textures->north_text);
// 	if (!cub3d->textures->north_text)
// 		print_error(get_error_name(ERROR_LOAD));
// 	cub3d->textures->south_text = mlx_load_png(cub3d->textures->south_text);
// 	if (!cub3d->textures->south_text)
// 		print_error(get_error_name(ERROR_LOAD));
// 	cub3d->textures->west_text = mlx_load_png(cub3d->textures->west_text);
// 	if (!cub3d->textures->west_text)
// 		print_error(get_error_name(ERROR_LOAD));
// 	cub3d->textures->east_text = mlx_load_png(cub3d->textures->east_text);
// 	if (!cub3d->textures->east_text)
// 		print_error(get_error_name(ERROR_LOAD));
// }