/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:37:23 by iris              #+#    #+#             */
/*   Updated: 2024/05/09 16:43:21 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_and_load_textures(t_cub3d *cub3d, char **file)
{
	char		*str;
	int			i;
	int			id;

	i = 0;
	ft_bzero((void *)&cub3d->textures, sizeof(t_textures));
	while (file[i])
	{
		str = file[i];
		str += skip_whitespace(str, 0);
		id = which_element(str);
		if (!id)
			break ;
		str = skip_path_prefix(str, id);
		load_element(cub3d, str, id);
		i++;
	}
	if (all_elements_loaded(&cub3d->textures))
		return (i);
	return (0);
}

void	load_element(t_cub3d *cub3d, char *path, int id)
{
	if (id == NO)
		cub3d->textures.north = path;
	else if (id == SO)
		cub3d->textures.south = path;
	else if (id == WE)
		cub3d->textures.west = path;
	else if (id == EA)
		cub3d->textures.east = path;
	else if (id == F || id == C)
		parse_colours(path, id, &cub3d->textures);
}

bool	load_wall_img(char *path, mlx_texture_t **texture)
{
	if (*texture)
		error_exit(DOUBLE_ELEMENT, 1);
	*texture = mlx_load_png(path);
	if (!*texture)
		error_exit("loading path error", 1);
	return (true);
}

bool	parse_colours(char *path, int id, t_textures *textures)
{
	char		**components;
	uint32_t	colour;

	components = ft_split(path, ',');
	if (!components || ptrarr_len((void **)components) != 3)
	{
		free_map_2d(components);
		return (false);
	}
	colour = get_rgba(ft_atoi(components[0]), ft_atoi(components[1]),
			ft_atoi(components[2]), 255);
	if ((id == C && textures->ceiling_colour) || \
		(id == F && textures->floor_colour))
		error_exit(DOUBLE_ELEMENT, 1);
	if (id == F)
		textures->floor_colour = colour;
	else if (id == C)
		textures->ceiling_colour = colour;
	free_map_2d(components);
	return (true);
}
