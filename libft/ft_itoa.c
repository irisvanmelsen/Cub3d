/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 12:19:58 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/21 17:45:03 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_length(int n)
{
	int	a;

	a = 1;
	if (n <= 0)
		a++;
	while (n != 0)
	{
		a++;
		n = n / 10;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;
	int		i;

	length = ft_length(n);
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (length));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[length - 2 - i++] = '0' + n % 10;
		n = n / 10;
	}
	str[length - 1] = '\0';
	return (str);
}
/*
int	main(void)
{
	int	str = 123;
	printf("%s", ft_itoa(str));
	return (0);
}*/
