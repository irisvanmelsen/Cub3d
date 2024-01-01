/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:49:03 by ivan-mel          #+#    #+#             */
/*   Updated: 2022/11/01 18:10:45 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			count++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
		}
		if (s[i] == '\0')
			return (count);
	i++;
	}
	return (count);
}

int	ft_wordlength(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
}

void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
	{
		free(array[i]);
		i++;
	}
	free (array);
	return ;
}

void	ft_loopsplit(char const *s, char **array, char c)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\0' && s[i] != c)
		{
			array[index] = ft_substr(s, i, ft_wordlength(s + i, c));
			if (!array[index])
			{
				ft_free(array);
			}
			index++;
			i = i + ft_wordlength(s + i, c);
			if (s[i] == '\0')
				break ;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		index;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	array = ft_calloc(sizeof(char *), (ft_wordcount(s, c) + 1));
	if (!array)
		return (NULL);
	ft_loopsplit(s, array, c);
	return (array);
}

/*
int	main(void)
{
	const char *str = "     hi";
	char b  = 32;
	char **array = ft_split(str, b);
	int i = 0;
	while (array[i]) {
		printf("word %i: %s\n", i, array[i]);
		i++;
	}
	return (0);
}*/