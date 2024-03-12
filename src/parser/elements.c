/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:37:23 by iris              #+#    #+#             */
/*   Updated: 2024/03/12 11:15:02 by ivan-mel         ###   ########.fr       */
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
		id =  which_element(str);
		if (!id)
			break;
		str = skip_path_prefix(str, id);
		load_element(cub3d, str, id);
		i++;
	}
	if (all_elements_loaded(&cub3d->textures))
		return (i);
	return (0); //print invalid line or not all elements?
}

void	load_element(t_cub3d *cub3d, char *path, int id)
{
	//damn actuallyyy if we make the textures an array we can index
	//directly into the ID enum
	if (id == NO)
		load_wall_img(path, &cub3d->textures.north);
	else if (id == SO)
		load_wall_img(path, &cub3d->textures.south);
	else if (id == WE)
		load_wall_img(path, &cub3d->textures.west);
	else if (id == EA)
		load_wall_img(path, &cub3d->textures.east);
	else if (id == F || id == C)
		parse_colours(path, id, &cub3d->textures);
}

bool	load_wall_img(char *path, mlx_texture_t **texture)
{
	printf("\n\nPATH IS: \"%s\"\n\n", path);
	if (*texture)
		error_exit(DOUBLE_ELEMENT, 1); //make this a clean free and exit program?
	*texture = mlx_load_png(path); //leaks.. mlx or us?
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
