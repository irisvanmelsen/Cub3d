/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memmove.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 13:43:06 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/14 19:20:29 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			a;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	a = len;
	if (d == 0 && s == 0)
		return (0);
	if (d > s)
	{
		while (a-- > 0)
		{
			d[a] = s[a];
		}
	}
	else
		a = 0;
	while (a < len)
	{
		d[a] = s[a];
		a++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	*d;
	char	s [] = "";
	char	*d1;
	char	s1 [] = "";
	size_t a = 3;
	d = s + 3;
	d1 = s1 + 3;
	printf("%s", ft_memmove(d, s, a));
	printf("\n");
	printf("%s", memmove(d1, s1, a));
	return (0);
}*/
