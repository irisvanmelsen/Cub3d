/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isdigit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:42:40 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/11 16:05:07 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%d", ft_isdigit('1'));
	return (0);
}*/
