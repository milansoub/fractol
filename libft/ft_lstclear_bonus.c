/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:34:24 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 12:51:53 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	temp = (**lst).next;
	ft_lstdelone(*lst, del);
	while (temp != NULL)
	{
		*lst = temp;
		temp = temp->next;
		ft_lstdelone(*lst, del);
	}
	*lst = NULL;
}
