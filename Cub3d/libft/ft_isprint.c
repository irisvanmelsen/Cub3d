/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isprint.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:39:39 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/12 11:55:48 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isprint(int a)
{
	if (a >= 32 && a <= 126)
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%d", ft_isprint(33));
	return (0);
}*/
