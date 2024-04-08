
int	is_game_key_pressed(mlx_t *mlx)
{
	int	i;
	const int keys[] = {MLX_KEY_W, MLX_KEY_S, MLX_KEY_D, MLX_KEY_A, \
						MLX_KEY_LEFT, MLX_KEY_RIGHT};
	i = 0;

	while (i < sizeof(keys) / sizeof(int) - 1)
	{
		if (mlx_is_key_down(mlx, keys[i]))
			return (i);
	}
	return (0);
}

void	movement_loop(void *param)
{
	t_cub3d *p;

	p = param;
	const int key = is_game_key_pressed(p);
	if (!key)
		return;
	if (key == 0)
		move(&p->player, p->player.dir, false);
	if (key == 1)
		move(&p->player, p->player.dir, true);
	if (key == 2)
		move(&p->player, p->player.dir, false);
	if (key == 3)
		move(&p->player, p->player.dir, true);

	ft_bzero(p->wall->pixels, WIDTH * HEIGHT * 4);
	raycaster(p->raycast);
}


void	draw_line(int lineheight, int colour, int *img, int start)
{
	while (lineheight)
	{
	img[70] = colour;
		lineheight--;
		start += WIDTH;
	}

// }

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

void	take_step_y(t_player *player, t_map *map, int step, double del_time)
{
	const int	dir = player->dir.y;
	if (map->content[(int)player->pos.y + step][(int)player->pos.x] == '0')
		player->pos.y += ((double)step * 0.15);
	ft_bzero(player->data->wall->pixels, WIDTH * HEIGHT * 4);
	raycaster(player->data->raycast);
}

void	take_step_x(t_player *player, t_map *map, int step, double del_time)
{
	if (map->content[(int)player->pos.y][(int)player->pos.x + step] == '0')
		player->pos.x += ((double)step * 0.15);
	ft_bzero(player->data->wall->pixels, WIDTH * HEIGHT * 4);
	raycaster(player->data->raycast);
}
