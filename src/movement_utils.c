/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:07:57 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/05/09 17:11:27 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	if_newpos_is_zero(t_cub3d *m, t_vector newpos)
{
	m->player.pos.x = newpos.x;
	m->player.pos.y = newpos.y;
}
