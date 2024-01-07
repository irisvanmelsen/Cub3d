/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexafunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:55:23 by ivan-mel          #+#    #+#             */
/*   Updated: 2022/11/09 15:11:17 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	printhexalow(unsigned long nb, char const *str)
{
	unsigned int	counter;

	counter = 0;
	if (nb < 16)
	{
		counter += printchar(str[nb]);
	}
	if (nb >= 16)
	{
		counter += printhexalow(nb / 16, "0123456789abcdef");
		counter += printhexalow(nb % 16, "0123456789abcdef");
	}
	return (counter);
}

int	printhexaup(unsigned long nb, char const *str)
{
	unsigned int	counter;

	counter = 0;
	if (nb < 16)
	{
		counter += printchar(str[nb]);
	}
	if (nb >= 16)
	{
		counter += printhexaup(nb / 16, "0123456789ABCDEF");
		counter += printhexaup(nb % 16, "0123456789ABCDEF");
	}
	return (counter);
}
