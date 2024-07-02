/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 21:53:03 by iris          #+#    #+#                 */
/*   Updated: 2024/05/09 16:46:07 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	ft_strlen_protect(char *s) //put these in libft?
{
	int	length;

	length = 0;
	if (s == NULL)
		return (0);
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

size_t	ft_strlcpy_protect(char *dst, char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (src == NULL)
		return (0);
	while (src[len] != '\0')
		len++;
	if (dstsize == 0)
		return (len);
	while (i < dstsize -1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str3;
	int		lengths1;
	int		lengths2;

	lengths1 = ft_strlen_protect(s1);
	lengths2 = ft_strlen_protect(s2);
	str3 = ft_calloc(sizeof(char), (lengths1 + lengths2 + 1));
	if (!str3)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	ft_strlcpy_protect(str3, s1, lengths1 + 1);
	ft_strlcat(str3 + lengths1, s2, lengths2 + 1);
	free(s1);
	free(s2);
	return (str3);
}

bool	free_line_if_empty(char *line)
{
	int	i;

	i = skip_whitespace(line, 0);
	if (!line[i])
	{
		free(line);
		return (true);
	}
	return (false);
}

void	free_map_2d(char **map_copy)
{
	int	i;

	i = 0;
	if (!map_copy || !map_copy[i])
		return ;
	while (map_copy[i])
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}
