/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 16:54:47 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/01/30 16:54:47 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_time(t_map *map)
{
	mlx_t	*mlx;
	mlx_image_t *imgs[5];
	mlx_texture_t	*texture[5];

	mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "EPIC", true);
	texture[0] = mlx_load_png(map->content[0] + 3);
	imgs[0] = mlx_texture_to_image(mlx, texture[0]);
	mlx_image_to_window(mlx, imgs[0], SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	mlx_loop(mlx);
	mlx_terminate(mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 16:54:47 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/01/30 16:54:47 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void mlx_time(void)
{

	mlx_t	*mlx;
	mlx_image_t *imgs[5];
	mlx_texture_t	*texture[5];

	mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "EPIC", true);
	texture[0] = mlx_load_png(map->content[0] + 3);
	imgs[0] = mlx_texture_to_image(mlx, texture[0]);
	mlx_image_to_window(mlx, imgs[0], SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	mlx_loop(mlx);
	mlx_terminate(mlx);
}
