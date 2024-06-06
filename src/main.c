/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 14:46:06 by iris          #+#    #+#                 */
/*   Updated: 2024/05/09 14:16:14 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mm_update(t_cub3d *cub3d, t_minimap *minimap);

int	main(int argc, char **argv)
{
	if (!cubed(argc, argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	cubed(int argc, char **argv)
{
	t_cub3d			cub3d;
	t_map			map;
	t_raycast_data	raycast;

	if (!parsing(argc, argv, &cub3d, &map))
		return (print_error("PARSING ERROR\n"));
	init_cub3d_data(&cub3d, &map, &raycast);
	game_setup(&cub3d);
	mlx_terminate(cub3d.mlx);
	free_all(&cub3d);
	return (1);
}

void	main_game_loop(void *param)
{
	t_cub3d		*m;
	t_vector	newpos;

	m = param;
	newpos.x = m->player.pos.x;
	newpos.y = m->player.pos.y;
	if (!keypress_check(m, &newpos))
		return ;
	if (m->map->content[(int)newpos.y][(int)newpos.x] == '0')
	{
		m->player.pos.x = newpos.x;
		m->player.pos.y = newpos.y;
	}
	mm_update(m, m->minimap);
	mouse_rotation(m);
	ft_bzero(m->wall->pixels, WIDTH * HEIGHT * 4);
	raycaster(m->raycast);
}
