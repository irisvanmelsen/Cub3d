/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memcmp.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 10:54:59 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/11 16:13:51 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*s;
	size_t			a;
	size_t			b;

	str = (unsigned char *)s1;
	s = (unsigned char *)s2;
	a = 0;
	b = 0;
	while (n > 0)
	{
		if (str[a] != s[b])
			return (str[a] - s[b]);
		n--;
		a++;
		b++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1 [] = "";
	char	str2 [] = "";
	size_t	a = 3;
	printf("%d", ft_memcmp(str1, str2, a));
	printf("\n");
	printf("%d", memcmp(str1, str2, a));
	return (0);
}*/
