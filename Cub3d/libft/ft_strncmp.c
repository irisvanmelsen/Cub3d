/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strncmp.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:31:38 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/12 17:15:42 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				a;
	size_t				b;
	unsigned char		*c;
	unsigned char		*d;

	c = (unsigned char *)s1;
	d = (unsigned char *)s2;
	a = 0;
	b = 0;
	if (n == 0)
		return (0);
	while (c[a] != '\0' && d[a] != '\0' && c[a] == d[a] && a < n -1)
		a++;
	b = c[a] - d[a];
	return (b);
}
/*
int	main(void)
{
	char	str1 [] = "Hellohello";
	char	str2 [] = "Ello";
	size_t	a = 3;
	printf("%d", strncmp(str1, str2, a));
	printf("\n");
	printf("%d", ft_strncmp(str1, str2, a));
	return (0);
}*/
