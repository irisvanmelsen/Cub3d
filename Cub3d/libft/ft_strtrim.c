/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 15:05:56 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/21 17:49:44 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) != '\0' && i < ft_strlen(s1))
		i++;
	while (ft_strchr(set, s1[j]) != '\0' && i < j)
			j--;
	result = ft_substr(s1, i, (j - i + 1));
	return (result);
}
/*
int	main(void)
{
	char const str [] = "  \t \t \n   \n\n\n\t";
	char const str1 [] = " \n\t";
	printf("%s", ft_strtrim(str, str1));
	return (0);
}*/
