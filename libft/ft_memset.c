/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memset.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 16:18:30 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/12 12:05:29 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	s;
	size_t			a;

	str = (unsigned char *)b;
	s = (unsigned char)c;
	a = 0;
	while (a < len)
	{
		str[a] = s;
		a++;
	}
	b = (void *)str;
	return (b);
}
/*
int	main(void)
{
	char	str [] = "Hello";
	int	c = 'A';
	size_t len = 3;
	printf("%s", ft_memset(str, c, len));
	printf("\n");
	printf("%s", memset(str, c, len));
	return (0);
}*/
