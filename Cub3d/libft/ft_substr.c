/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:07:29 by ivan-mel          #+#    #+#             */
/*   Updated: 2022/11/01 17:32:13 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s1;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	while (s[i] != '\0')
	{
		if (j < len && i >= start)
		{
			s1[j] = s[i];
			j++;
		}
		i++;
	}
	s1[j] = '\0';
	return (s1);
}
/*
int	main(void)
{
	ft_substr("hola", 0, 18446744073709551615);
}*/
