/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlcpy.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 11:00:01 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/12 17:25:54 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (dstsize == 0)
		return (len);
	while (i < dstsize -1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*
int	main(void)
{
	char	str [200];
	char	str1 [200];
	char	s [] = "ooo";
	char	s1 [] = "ooo";
	size_t	a = 0;
	printf("%lu", ft_strlcpy(str, s, a));
	printf("\n");
	printf("%lu", strlcpy(str1, s1, a));
	return(0);
}*/
