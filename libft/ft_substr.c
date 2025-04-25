/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:31:18 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 12:55:56 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <malloc.h>

static void	allocate(char **sub, const char *s, size_t len)
{
	size_t	str_l;

	str_l = ft_strlen(s);
	if (len > str_l)
		*sub = malloc(str_l + 1);
	else
		*sub = malloc(len + 1);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		sub = malloc(1);
		if (sub == NULL)
			return (NULL);
		*sub = 0;
		return (sub);
	}
	allocate(&sub, s + start, len);
	if (sub == NULL)
		return (NULL);
	while (s[start + i] != 0 && i < len)
	{
		sub[i] = s[start + i];
		++i;
	}
	sub[i] = 0;
	return (sub);
}
