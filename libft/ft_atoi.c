/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 10:56:30 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/12 15:23:13 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	count;
	int	minus;
	int	result;

	count = 0;
	minus = 1;
	result = 0;
	while ((str[count] >= 9 && str[count] <= 13) || str[count] == 32)
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			minus *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		result *= 10;
		result += str[count] - '0';
		count++;
	}
	result *= minus;
	return (result);
}
/*
int	main(void)
{
	char	str [] = "123";
	char	st [] = "--+--123";
	char	s [] = "65/123";
	char	str1 [] = "123";
	char	st1 [] = "--+--123";
	char	s1 [] = "65/123";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", ft_atoi(st));
	printf("%d\n", ft_atoi(s));
	printf("%d\n", atoi(str1));
	printf("%d\n", atoi(st1));
	printf("%d\n", atoi(s1));
	return(0);
} */
