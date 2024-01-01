/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:38:19 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/04/11 16:15:11 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	i = 0;
	if (ptr == NULL)
		return (ptr);
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
/*
int	main(void)
{
	ft_calloc(5, 4);
}*/
