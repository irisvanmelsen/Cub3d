/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   elements.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/31 00:37:23 by iris          #+#    #+#                 */
/*   Updated: 2024/07/02 17:15:10 by ivan-mel      ########   odam.nl         */
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
		if (!load_element(cub3d, str, id))
			return (0);
		i++;
	}
	if (all_elements_loaded(&cub3d->textures))
		return (i);
	return (0);
}

bool	load_element(t_cub3d *cub3d, char *path, int id)
{
	mlx_texture_t	*texture;

	if (id == F || id == C)
		return (parse_colours(path, id, &cub3d->textures));
	texture = mlx_load_png(path);
	if (!texture)
		return (print_error(get_error_name(ERROR_LOAD)));
	if (id == NO)
		cub3d->textures.north = texture;
	else if (id == SO)
		cub3d->textures.south = texture;
	else if (id == WE)
		cub3d->textures.west = texture;
	else if (id == EA)
		cub3d->textures.east = texture;
	return (true);
}

bool	parse_colours(char *path, int id, t_textures *textures)
{
	char		**components;
	int			rgb[3];

	components = ft_split(path, ',');
	if (!components || ptrarr_len((void **)components) != 3)
	{
		free_map_2d(components);
		return (false);
	}
	rgb[R] = ft_atoi(components[0]);
	rgb[G] = ft_atoi(components[1]);
	rgb[B] = ft_atoi(components[2]);
	free_map_2d(components);
	if (rgb[R] < 0 || rgb[R] > 255 || rgb[G] < 0 || rgb[G] > 255 \
		|| rgb[B] < 0 || rgb[B] > 255)
		return (false);
	if ((id == C && textures->ceiling_colour) || \
		(id == F && textures->floor_colour))
		error_exit(DOUBLE_ELEMENT, 1);
	if (id == F)
		textures->floor_colour = get_rgba(rgb[R], rgb[G], rgb[B], 255);
	else
		textures->ceiling_colour = get_rgba(rgb[R], rgb[G], rgb[B], 255);
	return (true);
}
