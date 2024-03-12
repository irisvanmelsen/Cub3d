/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:20:50 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/03/12 13:27:02 by ivan-mel         ###   ########.fr       */
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
	start_minimap(&cub3d);
	return (1);
}
