/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/01 16:58:17 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/03/01 16:58:17 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	rotate_vector(t_vector *vector, double angle);
t_vector	rotate_vector_return(t_vector vector, double angle);
void	move(t_player *player, t_vector dir, bool	subtract, t_vector *newpos);
void	change_dir(t_player	*player, bool looking_right);

void	cub3d_loop(void	*param)
{
	t_cub3d		*m;
	t_vector	newpos;

	m = param;
	newpos.x = m->player.pos.x;
	newpos.y = m->player.pos.y;

	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(m->mlx);
	if (mlx_is_key_down(m->mlx, MLX_KEY_W))
		move(&m->player, m->player.dir, false, &newpos);
	if (mlx_is_key_down(m->mlx, MLX_KEY_S))
		move(&m->player, m->player.dir, true, &newpos);
	if (mlx_is_key_down(m->mlx, MLX_KEY_D))
		move(&m->player, rotate_vector_return(m->player.dir, M_PI_2), true, &newpos);
	if (mlx_is_key_down(m->mlx, MLX_KEY_A))
		move(&m->player, rotate_vector_return(m->player.dir, M_PI_2), false, &newpos);
	if (mlx_is_key_down(m->mlx, MLX_KEY_LEFT))
		change_dir(&m->player, false);
	if (mlx_is_key_down(m->mlx, MLX_KEY_RIGHT))
		change_dir(&m->player, true);

	if (m->map->content[(int)newpos.y][(int)newpos.x] == '0')
	{
		m->player.pos.x = newpos.x;
		m->player.pos.y = newpos.y;
	}
	ft_bzero(m->wall->pixels, WIDTH * HEIGHT * 4);
	raycaster(m->raycast);
}

void	move(t_player *player, t_vector dir, bool	subtract, t_vector *newpos)
{
	double		speed;

	speed = 2.5 * player->data->mlx->delta_time; //move to struct if changeable or to move_loop if same for move and rotate
	if (mlx_is_key_down(player->data->mlx, MLX_KEY_LEFT_SHIFT))
		speed *= 2.5;
	if(subtract)
	{
		newpos->x -= (dir.x * speed);
		newpos->y -= (dir.y * speed);
	}
	else
	{
		newpos->x += (dir.x * speed);
		newpos->y += (dir.y * speed);
	}
}


void	change_dir(t_player	*player, bool looking_right)
{
	double	speed;//delta time

	speed = 1.5 * player->data->mlx->delta_time;
	if (looking_right)
		speed *= -1;
	rotate_vector(&player->dir, speed);
	rotate_vector(&player->plane, speed);
}

//angle is in radians (90* is half pi)
void	rotate_vector(t_vector *vector, double angle)
{
	const double old_x = vector->x;
	vector->x = old_x * cos(angle) - vector->y * sin(angle);
	vector->y = old_x * sin(angle) + vector->y * cos(angle);
}

t_vector	rotate_vector_return(t_vector vector, double angle)
{
	t_vector	ret;

	ret.x = vector.x * cos(angle) - vector.y * sin(angle);
	ret.y = vector.x * sin(angle) + vector.y * cos(angle);
	return (ret);
}
