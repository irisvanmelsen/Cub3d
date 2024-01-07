/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strrchr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 12:44:08 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/14 19:23:00 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (*(str + i) == (char)c)
			return ((char *) str + i);
	i--;
	}
	return (0);
}
/*
int	main(void)
{
	char	str [] = "testeiii";
	int	b = 0;
	printf("%s\n", ft_strrchr(str, b));
	printf("%s", strrchr(str, b));
	return (0);
}*/
