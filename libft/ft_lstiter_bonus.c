/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:40:53 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 12:52:11 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (lst == NULL)
		return ;
	if (lst->content != NULL)
		f(lst->content);
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (lst->content != NULL)
			f(lst->content);
	}
}
