/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: iris <iris@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 14:46:06 by iris          #+#    #+#                 */
/*   Updated: 2024/03/15 18:28:39 by iris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_all(t_cub3d *data)
{
	// if (data->map)
	if (data->map->file_content)
		free_array(data->map->file_content);
	if (data->map->content)
		free(data->map->content);
	if (data->map->dup_content)
		free_array(data->map->dup_content);
	if (data->minimap->mm_array)
		//should array not be saved to update map?
	if (data->minimap)
		free(data->minimap);
	free(data->textures.north_text);
	free(data->textures.east_text);
	free(data->textures.south_text);
	free(data->textures.west_text);
}

int	main(int argc, char **argv)
{
	if (!cubed(argc, argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	cubed(int argc, char **argv)
{
	t_cub3d	cub3d;
	t_map	map;
	t_raycast_data raycast;

	if (!parsing(argc, argv, &cub3d, &map))
		return (print_error("PARSING ERROR\n"));
	init_cub3d_data(&cub3d, &map, &raycast);
	game_setup(&cub3d);
	// start_minimap(&cub3d);
	// mlx_terminate(cub3d.mlx);
	free_all(&cub3d);

	return (1);
}
