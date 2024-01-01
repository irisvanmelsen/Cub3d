/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlen.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 15:35:06 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/11 16:05:58 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
/*
int	main(void)
{
	char	*s = "Hello";
	printf ("%zu", ft_strlen(s));
	return (0);
}*/
