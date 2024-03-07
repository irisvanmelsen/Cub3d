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

	if (xpos < 10 || xpos > WIDTH - 10 || ypos < 10 || ypos > HEIGHT - 10)
		return (NULL);
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

void	*escape(mlx_key_data_t keydata, void *param)
{
	t_cub3d *m;

	m = (t_cub3d *)param;

	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(m->mlx);
		// mlx_terminate(m->mlx);
	return (NULL);
}

void	cub3d_loop(void	*param)
{
	t_cub3d *m;

	m = param;

	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(m->mlx);
	if (mlx_is_key_down(m->mlx, MLX_KEY_W))
		take_step_y(&m->player, m->map, -1, m->mlx->delta_time);
	if (mlx_is_key_down(m->mlx, MLX_KEY_UP))
		take_step_y(&m->player, m->map, -1, m->mlx->delta_time);
	if (mlx_is_key_down(m->mlx, MLX_KEY_S))
		take_step_y(&m->player, m->map, 1, m->mlx->delta_time);
	if (mlx_is_key_down(m->mlx, MLX_KEY_DOWN))
		take_step_y(&m->player, m->map, 1, m->mlx->delta_time);
	if (mlx_is_key_down(m->mlx, MLX_KEY_D))
		take_step_x(&m->player, m->map, -1, m->mlx->delta_time);
	if (mlx_is_key_down(m->mlx, MLX_KEY_RIGHT))
		take_step_x(&m->player, m->map, -1, m->mlx->delta_time);
	if (mlx_is_key_down(m->mlx, MLX_KEY_A))
		take_step_x(&m->player, m->map, 1, m->mlx->delta_time);
	if (mlx_is_key_down(m->mlx, MLX_KEY_LEFT))
		take_step_x(&m->player, m->map, 1, m->mlx->delta_time);
}

take_step_y(t_player *player, t_map *map, int step, double del_time)
{

}

take_step_x(t_player *player, t_map *map, int step, double del_time)
{

}
