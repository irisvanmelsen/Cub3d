/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:09:47 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/02/23 17:09:47 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	vector_divide(t_vector src, t_vector divider)
{
	t_vector ret;
	ret.y = src.y / divider.y;
	ret.x = src.x / divider.x;
	return (ret);
}

// void	vector_add(t_vector src, t_vector addition, t_vector *ret)
// {
// 	*ret[Y] = src[Y] + addition[Y];
// 	*ret[X] = src[X] + addition[X];
// }

// void	vector_subtract(t_vector src, t_vector subtraction, t_vector *ret)
// {
// 	*ret[Y] = src[Y] - subtraction[Y];
// 	*ret[X] = src[X] - subtraction[X];
// }
