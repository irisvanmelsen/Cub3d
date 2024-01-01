/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memchr.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 16:57:11 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/12 15:12:29 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	void	*result;
	size_t	a;

	str = (char *)s;
	a = 0;
	while (a < n)
	{
		if (str[a] == (char)c)
		{
			result = (void *)&str[a];
			return (result);
		}
	a++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str [] = "Hallo";
	int	c = 97;
	size_t n = 3;
	printf("%s", ft_memchr(str, c, n));
	printf("\n");
	printf("%s", memchr(str, c, n));
	return (0);
}*/
