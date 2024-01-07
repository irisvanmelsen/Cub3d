/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:37:23 by iris              #+#    #+#             */
/*   Updated: 2024/01/07 18:40:33 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*take_out_newlines(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[i] == '\n')
		return (false);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			j = i;
			while (str[j] != '\0')
			{
				str[j] = str[j+1];
				j++;
			}
		}
		else
			i++;
	}
	return (str);
}

int	check_elements(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (NO);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (SO);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (WE);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (EA);
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (F);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (C);
	return (FAILED);
}

bool	set_element_color(char *path, int id, t_elements *element)
{
	if (id == 'F')
	{
		element->floor_column = parse_colours(path, id, element);
		if (!element->floor_column)
			return (false);
	}
	else if (id == 'C')
	{
		element->ceiling_column = parse_colours(path, id, element);
		if (!element->ceiling_column)
			return (false);
	}
	return (true);
}

void	texture_init(t_textures *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
}

bool	use_elements(char *path, int id, t_elements *element)
{
	t_textures	*texture;

	texture = malloc(sizeof(t_textures));
	if (!texture)
		return (false);
	texture_init(texture);
	if (id == NO)
	{
		printf("check?\n");
		if (!get_north_path(texture, path))
			return (printf("Texture uploading of NO went wrong!\n"), false);
		return (NO);
	}
	else if (id == SO)
	{
		if (!get_south_path(texture, path))
			return (printf("Texture uploading of SO went wrong!\n"), false);
		return (SO);
	}
	else if (id == WE)
	{
		if (!get_west_path(texture, path))
			return (printf("Texture uploading of WE went wrong!\n"), false);
		return (WE);
	}
	else if (id == EA)
	{
		if (!get_east_path(texture, path))
			return (printf("Texture uploading of EA went wrong!\n"), false);
		return (EA);
	}
	else if (id == F)
	{
		if (!parse_colours(path, id, element))
			return (printf("Colour uploading went wrong!\n"), false);
		return (F);
	}
	else if (id == C)
	{
		if (!parse_colours(path, id, element))
			return (printf("Colour uploading went wrong!\n"), false);
		return (C);
	}
	return (false);
}

bool	parse_elements_in_map(char **map)
{
	char		*str;
	int			i;
	int			id;
	t_elements	*element;

	i = 0;
	id = 0;
	element = NULL;
	while (i < 6)
	{
		str = take_out_newlines(map[i]);
		if (!str)
			return (false);
		id = check_elements(str);
		if (!id)
		{
			free_map_2d(map);
			return (false);
		}
		use_elements(str, id, element);
		i++;
	}
	return (true);
}