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
	mlx_t *mlx;

	mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "EPIC", true);
	while (1)
	{
		mlx_loop(mlx);
	}
	mlx_terminate(mlx);
}
