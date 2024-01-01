/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memcpy.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 13:17:53 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/12 14:06:33 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*d;
	char			*s;
	size_t			a;

	d = (char *)dst;
	s = (char *)src;
	a = 0;
	if (d == 0 && s == 0)
		return (0);
	while (a < n)
	{
		d[a] = s[a];
		a++;
	}
	dst = (void *)d;
	return (dst);
}
/*
int	main(void)
{
	char	str [] = "";
	char	s [] = "";
	size_t a = 3;
	printf("%s", ft_memcpy(str, s, a));
	printf("\n");
	printf("%s", memcpy(str, s, a));
	return (0);
}*/
