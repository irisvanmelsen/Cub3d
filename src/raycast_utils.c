/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:28:12 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/05/09 16:50:54 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	coordinate_on_textures(t_raycast_data *ray, t_textures *texture)
{
	texture->texx = (int)(texture->wallx * (double)texture->used_tex->width);
	if (ray->side_hit == HORIZONTAL && ray->raydir.x > 0)
		texture->texx = texture->used_tex->width - texture->texx - 1;
	if (ray->side_hit == VERTICAL && ray->raydir.y < 0)
		texture->texx = texture->used_tex->width - texture->texx - 1;
}
