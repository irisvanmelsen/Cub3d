/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:33:01 by ivan-mel          #+#    #+#             */
/*   Updated: 2022/11/09 15:11:17 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	printstr(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		counter += printchar(str[i]);
		i++;
	}
	return (counter);
}

int	putnbr(int nb)
{
	int	counter;

	counter = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		nb = nb * -1;
		counter += printchar('-');
	}
	if (nb < 10)
	{
		counter += printchar(nb + '0');
	}
	if (nb >= 10)
	{
		counter += putnbr(nb / 10);
		counter += putnbr(nb % 10);
	}
	return (counter);
}

int	putun(unsigned int nb)
{
	unsigned int	counter;

	counter = 0;
	if (nb < 10)
		counter += printchar(nb + '0');
	if (nb >= 10)
	{
		counter += putnbr(nb / 10);
		counter += putnbr(nb % 10);
	}
	return (counter);
}
