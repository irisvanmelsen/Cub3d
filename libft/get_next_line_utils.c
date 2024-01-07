/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:34:14 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/23 14:40:27 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// checkchar: 
// this goes through 'buffy' to find out whether it has a
// '\0' (terminating character) or '\n' (new line) in the line.
// it basically returns a true (1) or false (0)
// depending on whether there is a '\n' or not. */

int	checkchar(char *buffy)
{
	int	i;

	i = 0;
	while (buffy[i] != '\0')
	{
		if (buffy[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// strlen:
// checks whether the string exists. If the string does exist then
// it will return the length of the string, otherwise it returns 0.

size_t	ft_strlengnl(const char *s)
{
	int	length;

	length = 0;
	if (!s)
		return (0);
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

// ft_callocgnl:
// this function allocates a specified amount of
// memory and then initialize it to zero
// it is similar to malloc but malloc does not initialize it to zero
// we do this by making sure we allocate enough space through malloc
// then we continue until to do so until i is equal to our count * size

void	*ft_callocgnl(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(count * size);
	i = 0;
	if (!str)
		return (str);
	while (i < (count * size))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
