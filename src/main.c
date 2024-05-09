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

void	free_all(t_cub3d *data) //put in utils?
{
	if (data->map->file_content)
		free_array(data->map->file_content);
	if (data->map->content)
		free(data->map->content);
	if (data->map->dup_content)
		free_array(data->map->dup_content);
	// if (data->minimap->mm_array)
		//should array not be saved to update map?
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
	t_cub3d	cub3d;
	t_map	map;
	t_raycast_data raycast;

	if (!parsing(argc, argv, &cub3d, &map))
		return (print_error("PARSING ERROR\n"));
	init_cub3d_data(&cub3d, &map, &raycast);
	game_setup(&cub3d);
	free_all(&cub3d);
	return (1);
}
