/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:12:03 by iris              #+#    #+#             */
/*   Updated: 2024/03/08 22:58:05 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_error_name(t_error error)
{
	static char	*str[] = {\
		[ERROR_CHARACTER] = "Invalid Amount of Positions!\n", \
		[ERROR_MLX] = "MLX Initialisation has Failed!\n", \
		[ERROR_IMAGE] = "MLX Image Initialisation has Failed!\n", \
		[ERROR_ALLOCATION] = "Allocation has Failed!\n"};

	return (str[error]);
}

bool	print_error(char *str)
{
	write (STDERR_FILENO, str, ft_strlen(str));
	return (false);
}
