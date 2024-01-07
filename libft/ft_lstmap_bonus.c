/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:28:05 by ivan-mel          #+#    #+#             */
/*   Updated: 2022/11/01 17:05:42 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*result;
	t_list	*current;
	void	*tmp2;

	current = lst;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	result = NULL;
	while (current != NULL)
	{
		tmp2 = f(current->content);
		tmp = ft_lstnew(tmp2);
		if (tmp == NULL)
		{
			ft_lstclear(&result, del);
			del(tmp2);
			return (NULL);
		}
		ft_lstadd_back(&result, tmp);
		current = current->next;
	}
	return (result);
}
