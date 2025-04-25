/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:46:21 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 12:55:47 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_char_find(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	length;

	i = 0;
	if (!big && len == 0)
		return (NULL);
	if (*little == 0)
		return ((char *)big);
	length = ft_strlen(little);
	while (big[i] != 0 && i < len && length <= len - i)
	{
		if (ft_char_find(little, big[i]))
		{
			if (ft_strncmp(little, big + i, length) == 0)
				return ((char *)big + i);
		}
		++i;
	}
	return (NULL);
}
