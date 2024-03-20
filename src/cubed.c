/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:20:50 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/03/19 22:48:56 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cubed(int argc, char **argv)
{
	t_cub3d	cub3d;
	t_map	map;

	ft_bzero(&cub3d, sizeof(cub3d));

	if (!parsing(argc, argv, &cub3d, &map))
		return (print_error("PARSING ERROR\n"));
	cub3d.map = &map;
	mlx_setup(&cub3d);
	// start_minimap(&cub3d);
	// mlx_terminate(cub3d.mlx);
	return (1);
}
