/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/06 14:58:37 by iris          #+#    #+#                 */
/*   Updated: 2024/02/02 14:42:19 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	get_north_path(t_cub3d *cub3d, t_textures *texture, char *path)
{
	printf("gets into function?\n");
	if (texture->north)
	{
		printf("Double element! NO should only be used once.\n");
		return (false);
	}
	texture->north = mlx_load_png("./textures/wall_bricks1.png");
	if (!texture->north)
		return (false);
	cub3d->player.direction = NO;
	return (true);
}

bool	get_south_path(t_cub3d *cub3d, t_textures *texture, char *path)
{
	if (texture->south)
	{
		printf("Double element! SO should only be used once.\n");
		return (false);
	}
	texture->south = mlx_load_png(path);
	if (!texture->south)
		return (false);
	cub3d->player.direction = SO;
	return (true);
}

bool	get_west_path(t_cub3d *cub3d, t_textures *texture, char *path)
{
	if (texture->west)
	{
		printf("Double element! WE should only be used once.\n");
		return (false);
	}
	texture->west = mlx_load_png(path);
	if (!texture->west)
		return (false);
	cub3d->player.direction = WE;
	return (true);
}

bool	get_east_path(t_cub3d *cub3d, t_textures *texture, char *path)
{
	if (texture->east)
	{
		printf("Double element! EA should only be used once.\n");
		return (false);
	}
	texture->east = mlx_load_png(path);
	if (!texture->east)
		return (false);
	cub3d->player.direction = EA;
	return (true);
}
