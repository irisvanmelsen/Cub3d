/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strchr.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 17:07:20 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/12 15:06:54 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *str, int a)
{
	int		b;
	char	*y;

	y = (char *)str;
	b = 0;
	while (y[b] != '\0')
	{
		if (y[b] == (char)a)
		{
			return (&y[b]);
		}
	b++;
	}
	if (y[b] == (char)a)
		return (&y[b]);
	return (0);
}
/*
int	main(void)
{
	char	str [] = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
//	int	b  = 90;
	char	str1 [] = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
//	int	b1 = 90;
	printf("%s", ft_strchr(str, '\0'));
	printf("\n");
	printf("%s", strchr(str1, '\0'));
	return (0);
}*/
