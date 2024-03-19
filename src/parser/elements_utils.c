/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 00:21:03 by iris              #+#    #+#             */
/*   Updated: 2024/03/17 12:58:43 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// this function returns the RGBA colour in hexadecimal notation
// r shifts 24s bits to the left so first byte
// g shifts 16 bits to the left and becomes second byte
// b shifts 8 bits to the left and becomes third byte
// a is places without shifting and is the fourth byte

uint32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

bool	all_elements_loaded(t_textures *checkme)
{
	if (!checkme->north || !checkme->east || !checkme->south || !checkme->west)
		return (false);
	if (!checkme->ceiling_colour || !checkme->floor_colour)
		return (false);
	return (true);
}

int	which_element(char *line) //can be merged with load element
{
	//make jumptable?
	if (ft_strncmp(line, "NO", 2) == 0) //does it always have a space after?
		return (NO);
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (SO);
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (WE);
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (EA);
	else if (ft_strncmp(line, "F", 1) == 0)
		return (F);
	else if (ft_strncmp(line, "C", 1) == 0)
		return (C);
	return (FAILED);
}

char	*skip_path_prefix(char *line, int id)
{
	if (id == F || id == C)
		line += 2;
	else
		line += 3;
	line += skip_whitespace(line, 0);
	return (line);
}
