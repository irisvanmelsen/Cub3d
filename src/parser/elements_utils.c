/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 00:21:03 by iris              #+#    #+#             */
/*   Updated: 2024/02/02 14:33:53 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// this function returns the RGBA colour in hexadecimal notation
// r shifts 24s bits to the left so first byte
// g shifts 16 bits to the left and becomes second byte
// b shifts 0 bits to the left and becomes third byte
// a is places without shifting and is the fourth byte

uint32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	amount_of_components(char **components)
{
	int	i;

	i = 0;
	while (components[i] != NULL)
		i++;
	return (i);
}

bool	parse_colours(char *path, int id, t_elements *element)
{
	char	**components;
	int		colour;

	components = ft_split(path, ',');
	if (!components)
	{
		free_map_2d(components);
		return (false);
	}
	if (amount_of_components(components) != 3)
	{
		free_map_2d(components);
		return (false);
	}
	colour = get_rgba(ft_atoi(components[0]), ft_atoi(components[1]),
			ft_atoi(components[2]), 255);
	if (id == F)
		element->floor_column = colour;
	else if (id == C)
		element->ceiling_column = colour;
	free_map_2d(components);
	return (true);
}
