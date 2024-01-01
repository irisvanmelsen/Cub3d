/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isascii.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:15 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/11 16:05:33 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%d", ft_isascii(128));
	return (0);
}*/
