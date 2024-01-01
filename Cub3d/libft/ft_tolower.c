/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tolower.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:28:14 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/11 16:12:41 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int a)
{
	if (a >= 65 && a <= 90)
	{
		a = a + 32;
	}
	return (a);
}
/*
int	main(void)
{
	printf("%c", ft_tolower('A'));
	return (0);
}*/
