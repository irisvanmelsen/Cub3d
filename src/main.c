/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: iris <iris@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 14:46:06 by iris          #+#    #+#                 */
/*   Updated: 2024/01/07 18:09:12 by iris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (!parsing(argc, argv, &map))
	{
	{
		printf("Parser error\n");
		return (EXIT_FAILURE);
	}
	if (!map.content || !*map.content)
		printf("\nAA\nAH\n\n");
	else
		print_2d_charray(map.content);
	mlx_time(&map);
	return (EXIT_SUCCESS);
}

	// print_2d_charray(map.content); map not 0 terminated?


	// print_2d_charray(map.content); map not 0 terminated?
