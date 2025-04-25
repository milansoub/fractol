/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:24:44 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/10 14:56:05 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_occurence;

	c %= 128;
	i = 0;
	last_occurence = NULL;
	while (s[i] != 0)
	{
		if (s[i] == c)
			last_occurence = (char *)s + i;
		++i;
	}
	if (s[i] == c)
		last_occurence = (char *)s + i;
	return (last_occurence);
}
