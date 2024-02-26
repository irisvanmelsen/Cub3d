/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_setup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 21:50:22 by iris          #+#    #+#                 */
/*   Updated: 2024/02/12 16:40:41 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cub3d_memset(void *b, int colour, size_t len)
{
	size_t	i;
	int		*img;

	img = b;
	i = 0;
	while (i < len)
	{
		img[i] = colour;
		i++;
	}
}

int	background_setup(mlx_image_t *background) //take parse
{
	if (!background)
	{
		print_error(get_error_name(ERROR_ALLOCATION));
		return (-1);
	}
	cub3d_memset(background->pixels, 0xffff0000, HALF_SCREENSIZE);
	cub3d_memset(&background->pixels[HALF_SCREENSIZE * 4], 0xff0000ff, HALF_SCREENSIZE);
	return (1);
}

// void	draw_line(int lineheight, int colour, int *img, int start)
// {
// 	while (lineheight)
// 	{
// 	img[70] = colour;
// 		lineheight--;
// 		start += WIDTH;
// 	}

// }
