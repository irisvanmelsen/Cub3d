/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:14:56 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/03/27 16:27:42 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	take_step_y(t_map *map, int y, int x, double delta_time)
{
	double	next_pos_x;
	double	next_pos_y;
	double	moving_speed;

	moving_speed = 0.2;
	if (y < 0)
	{
		next_pos_y = map->player_y - y * moving_speed;
		next_pos_x = map->player_x - x * moving_speed;
		if (map->content[(int)next_pos_y][(int)next_pos_x] == '1')
			
	}
}

void	cub3d_loop(void	*param)
{
	t_cub3d *m;

	m = param;

	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(m->mlx);
	if (mlx_is_key_down(m->mlx, MLX_KEY_W))
		take_step_y(m->map, -1, -1, m->mlx->delta_time);
	if (mlx_is_key_down(m->mlx, MLX_KEY_UP))
		take_step_y(m->map, -1, -1, m->mlx->delta_time);
	if (mlx_is_key_down(m->mlx, MLX_KEY_S))
		take_step_y(m->map, 1, m->mlx->delta_time);
	if (mlx_is_key_down(m->mlx, MLX_KEY_DOWN))
		take_step_y(m->map, 1, m->mlx->delta_time);
	if (mlx_is_key_down(m->mlx, MLX_KEY_D))
		take_step_x(m->map, -1, -1, m->mlx->delta_time);
	if (mlx_is_key_down(m->mlx, MLX_KEY_RIGHT))
		take_step_x(m->map, -1, -1, m->mlx->delta_time);
	if (mlx_is_key_down(m->mlx, MLX_KEY_A))
		take_step_x(m->map, 1, m->mlx->delta_time);
	if (mlx_is_key_down(m->mlx, MLX_KEY_LEFT))
		take_step_x(m->map, 1, m->mlx->delta_time);
}

