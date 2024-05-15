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

void	mm_update(t_cub3d *cub3d);


//move free all and mm update to utils
void	free_all(t_cub3d *data)
{
	if (data->map->file_content)
		free_array((void *)data->map->file_content);
	if (data->map->content)
		free(data->map->content);
	if (data->map->dup_content)
		free_array((void *)data->map->dup_content);
	if (data->minimap->mm_array)
		free_array((void *)data->minimap->mm_array);
	if (data->minimap)
		free(data->minimap);
	if (data->textures.north)
		free(data->textures.north);
	if (data->textures.east)
		free(data->textures.east);
	if (data->textures.south)
		free(data->textures.south);
	if (data->textures.west)
		free(data->textures.west);
}

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
	mm_update(m);
	mouse_rotation(m);
	ft_bzero(m->wall->pixels, WIDTH * HEIGHT * 4);
	raycaster(m->raycast);
}

void	mm_update(t_cub3d *cub3d)
{
	cub3d->minimap->mm_array = compare_maps(cub3d->minimap, \
		cub3d->minimap->mm_array, cub3d);
	fill_wall_backgr(cub3d->minimap->mm_array, cub3d->minimap);
}
