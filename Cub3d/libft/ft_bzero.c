/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bzero.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:46:27 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/12 13:28:55 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			a;

	str = (unsigned char *)s;
	a = 0;
	while (a < n)
	{
		str[a] = 0;
		a++;
	}
}
/*
int	main(void)
{
	char	str [] = "Hello";
	size_t len = 3;
	ft_bzero(str, len);
	printf("\n");
	printf("%s", bzero(str, len));
	return (0);
}*/
