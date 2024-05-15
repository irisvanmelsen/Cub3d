/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/01 16:58:17 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/05/09 17:08:20 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void		rotate_vector(t_vector *vector, double angle);
t_vector	rotate_vector_return(t_vector vector, double angle);
void		move(t_player *player, t_vector dir, bool	subtract, \
			t_vector *newpos);
void		change_dir(t_player	*player, bool looking_right);
void		mouse_rotation(t_cub3d *m);
void		mm_update(t_cub3d *cub3d);

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
		move(&m->player, rotate_vec_return(m->player.dir, M_PI_2), 1, &newpos);
	if (mlx_is_key_down(m->mlx, MLX_KEY_A))
		move(&m->player, rotate_vec_return(m->player.dir, M_PI_2), 0, &newpos);
	if (mlx_is_key_down(m->mlx, MLX_KEY_LEFT))
		change_dir(&m->player, false);
	if (mlx_is_key_down(m->mlx, MLX_KEY_RIGHT))
		change_dir(&m->player, true);
	if (m->map->content[(int)newpos.y][(int)newpos.x] == '0')
		if_newpos_is_zero(m, newpos);
	ft_bzero(m->wall->pixels, WIDTH * HEIGHT * 4);
	raycaster(m->raycast);
}

//set curseor to hidden in setup
void	mouse_rotation(t_cub3d *m)
{
	t_vector	mouse_pos;

	mlx_get_mouse_pos(m->mlx, &mouse_pos.x, &mouse_pos.y);
	if (mouse_pos.x == HALF_WIDTH || mouse_pos.y == HALF_HEIGHT)
		return ;
	mlx_set_mouse_pos(m->mlx, HALF_WIDTH, HALF_HEIGHT);
	if (mouse_pos.x < HALF_WIDTH - 10)
		change_dir(&m->player, false);
	else if (mouse_pos.x > HALF_WIDTH)
		change_dir(&m->player, true);
}

void	mm_update(t_cub3d *cub3d)
{
	cub3d->minimap->mm_array = compare_maps(cub3d->minimap->mm_array, \
		cub3d->minimap->og_map, (int)cub3d->player.pos.x, \
		(int)cub3d->player.pos.y);
	fill_wall_backgr(cub3d->minimap->mm_array, cub3d->minimap);
}

void	move(t_player *player, t_vector dir, bool	subtract, t_vector *newpos)
{
	double		speed;

	speed = 2.5 * player->data->mlx->delta_time;
	if (mlx_is_key_down(player->data->mlx, MLX_KEY_LEFT_SHIFT))
		speed *= 2.5;
	if (subtract)
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
	double	speed;

	speed = 1.5 * player->data->mlx->delta_time;
	if (looking_right)
		speed *= -1;
	rotate_vector(&player->dir, speed);
	rotate_vector(&player->plane, speed);
}

//angle is in radians (90* is half pi)
void	rotate_vector(t_vector *vector, double angle)
{
	const double	old_x = vector->x;

	vector->x = old_x * cos(angle) - vector->y * sin(angle);
	vector->y = old_x * sin(angle) + vector->y * cos(angle);
}

t_vector	rotate_vec_return(t_vector vector, double angle)
{
	t_vector	ret;

	ret.x = vector.x * cos(angle) - vector.y * sin(angle);
	ret.y = vector.x * sin(angle) + vector.y * cos(angle);
	return (ret);
}
