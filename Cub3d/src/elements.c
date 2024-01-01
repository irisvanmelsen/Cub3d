/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:37:23 by iris              #+#    #+#             */
/*   Updated: 2024/01/02 00:28:15 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	check_Elements(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (true);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (true);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (true);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (true);
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (true);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (true);
	return (false);
}

int	check_elements_in_map(char **map)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		check_elements(map[i]);
		i++;
	}
}