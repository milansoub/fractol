/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:01:08 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 12:55:08 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <malloc.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new_str;

	i = 0;
	new_str = malloc(ft_strlen(s) + 1);
	if (new_str == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		new_str[i] = f(i, s[i]);
		++i;
	}
	new_str[i] = 0;
	return (new_str);
}
