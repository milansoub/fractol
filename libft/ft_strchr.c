/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:22:19 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/10 14:55:59 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	c %= 128;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		++i;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}
