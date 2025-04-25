/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:43:09 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 12:56:04 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <malloc.h>

static char	ft_find_char(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	start;
	size_t	buffer_size;
	char	*new_str;

	i = 0;
	buffer_size = ft_strlen(s1) + 1;
	while (s1[i] != 0 && ft_find_char(set, s1[i]))
		++i;
	buffer_size -= i;
	start = i;
	if (start != ft_strlen(s1))
	{
		i = ft_strlen(s1) - 1;
		while (i != 0 && ft_find_char(set, s1[i]))
		{
			--buffer_size;
			--i;
		}
	}
	new_str = malloc(buffer_size);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1 + start, buffer_size);
	return (new_str);
}
