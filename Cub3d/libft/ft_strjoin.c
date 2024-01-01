/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 13:31:30 by ivan-mel      #+#    #+#                 */
/*   Updated: 2022/10/21 17:49:19 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str3;
	int		lengths1;
	int		lengths2;

	if (s1 == NULL || s2 == 0)
		return (NULL);
	lengths1 = ft_strlen(s1);
	lengths2 = ft_strlen(s2);
	str3 = malloc(sizeof(char) * (lengths1 + lengths2 + 1));
	if (!str3)
		return (NULL);
	ft_strlcpy(str3, s1, lengths1 + 1);
	ft_strlcat(str3 + lengths1, s2, lengths2 + 1);
	return (str3);
}
