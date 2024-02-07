/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: iris <iris@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/06 14:58:37 by iris          #+#    #+#                 */
/*   Updated: 2024/01/14 21:01:48 by iris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	get_north_path(t_cub3d *cub3d, t_textures *texture, char *path)
{
	if (texture->north)
		error_exit("Double element! NO should only be used once.\n", \
		EXIT_FAILURE);
	texture->north = mlx_load_png(path);
	if (!texture->north)
		return (false);
	cub3d->player.direction = NO;
	return (true);
}

bool	get_south_path(t_cub3d *cub3d, t_textures *texture, char *path)
{
	if (texture->south)
		error_exit("Double element! SO should only be used once.\n", \
		EXIT_FAILURE);
	texture->south = mlx_load_png(path);
	if (!texture->south)
		return (false);
	cub3d->player.direction = SO;
	return (true);
}

bool	get_west_path(t_cub3d *cub3d, t_textures *texture, char *path)
{
	if (texture->west)
		error_exit("Double element! WE should only be used once.\n", \
		EXIT_FAILURE);
	texture->west = mlx_load_png(path);
	if (!texture->west)
		return (false);
	cub3d->player.direction = WE;
	return (true);
}

bool	get_east_path(t_cub3d *cub3d, t_textures *texture, char *path)
{
	if (texture->east)
		error_exit("Double element! EA should only be used once.\n", \
		EXIT_FAILURE);
	texture->east = mlx_load_png(path);
	if (!texture->east)
		return (false);
	cub3d->player.direction = EA;
	return (true);
}
