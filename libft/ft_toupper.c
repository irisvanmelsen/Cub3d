/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   toupper.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:02:43 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/11 16:12:30 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_toupper(int a)
{
	if (a >= 97 && a <= 122)
	{
		a = a - 32;
	}
	return (a);
}
/*
int	main(void)
{
	printf("%c", ft_toupper('A'));
	return (0);
}*/
