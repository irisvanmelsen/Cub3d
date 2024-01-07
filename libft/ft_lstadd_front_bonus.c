/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:35:33 by ivan-mel          #+#    #+#             */
/*   Updated: 2022/10/31 16:51:29 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != '\0' && new != '\0')
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
void    main()
{
    t_list *head=malloc(sizeof(t_list));
    head->content = "42";
    head->next = NULL;

    t_list *current=malloc(sizeof(t_list));
    current->content = "84";
    current->next = NULL;
    head->next = current;

    t_list *current2=malloc(sizeof(t_list));
    current2->content = "128";
    current2->next = NULL;
    current->nextmak

}*/