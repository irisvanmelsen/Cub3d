/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_move.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/01 16:58:17 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/03/01 16:58:17 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*mouse_move(double xpos, double ypos, void	*param)
{
	const	t_cub3d	*data = (t_cub3d *)param;

	for (size_t i = 0; i < 10; i++)
	{
		mlx_put_pixel(data->wall, xpos + i, ypos + i, get_rgba(0, 255, 150, 255));
		mlx_put_pixel(data->wall, xpos + i, ypos - i, get_rgba(0, 255, 150, 255));
		mlx_put_pixel(data->wall, xpos - i, ypos + i, get_rgba(0, 255, 150, 255));
		mlx_put_pixel(data->wall, xpos - i, ypos - i, get_rgba(0, 255, 150, 255));
		// xpos++;
		// ypos++;
		i++;
	}

	return (NULL);
}
