/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 15:24:36 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/12 15:53:53 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	a;
	size_t	b;

	h = (char *)haystack;
	n = (char *)needle;
	a = 0;
	if (n[0] == '\0')
		return (h);
	while (h[a] != '\0')
	{
		b = 0;
		while (h[a + b] == n[b] && (a + b) < len)
		{
			if (n[b] == '\0' && h[a + b] == '\0')
				return (&h[a]);
		b++;
		}
		if (n[b] == '\0')
			return (h + a);
		a++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str [] = "Hello";
	char	s [] = "llo";
	char	str1 [] = "Hello";
	char	s1 [] = "llo";
	size_t a = 5;
	printf("%s", ft_strnstr(str, s, a));
	printf("\n");
	printf("%s", strnstr(str1, s1, a));
	return (0);
}*/
