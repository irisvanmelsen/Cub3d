/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:12:03 by iris              #+#    #+#             */
/*   Updated: 2024/04/09 21:00:23 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_error_name(t_error error)
{
	static char	*str[] = {\
		[ERROR_CHARACTER] = "Invalid Amount of Positions!\n", \
		[ERROR_MLX] = "MLX Initialisation has Failed!\n", \
		[ERROR_IMAGE] = "MLX Image Initialisation has Failed!\n", \
		[ERROR_ALLOCATION] = "Allocation has Failed!\n", \
		[ERROR_LOAD] = "Loading of Image has Failed!\n"};

	return (str[error]);
}

bool	print_error(char *str)
{
	write (STDERR_FILENO, str, ft_strlen(str));
	return (false);
}
