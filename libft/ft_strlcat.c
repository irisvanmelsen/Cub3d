/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlcat.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 15:19:10 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/12 17:46:59 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned char	*s;
	size_t			lendst;
	size_t			lensrc;
	size_t			total;
	size_t			i;

	s = (unsigned char *)src;
	lendst = 0;
	lensrc = 0;
	i = 0;
	while (dst[lendst] != '\0' && lendst < dstsize)
		lendst++;
	lensrc = ft_strlen(src);
	total = lendst + lensrc;
	if (dstsize > lendst)
	{
		while (lendst < dstsize -1 && s[i] != '\0')
		{
			dst[lendst] = s[i];
			i++;
			lendst++;
		}
		dst[lendst] = '\0';
	}
	return (total);
}
/*
int	main(void)
{
	char	str [100] = "Hello";
	char	s [] = "ABC";
	char	str1 [100] = "Hello";
	char	s1 [] = "ABC";
	size_t a = 10;
	printf("%zu \n", ft_strlcat(str, s, a));
	printf("%s dit is niet OG \n", str);
	printf("%zu \n", strlcat(str1, s1, a));
	printf("%s dit is OG \n", str1);
	return (0);
}*/
