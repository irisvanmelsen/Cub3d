/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isalpha.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:57:45 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/11 16:04:49 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return (1);
	return (0);
}	
/*
int	main(void)
{
	printf("%d", ft_isalpha('A'));
	return (0);
}*/
