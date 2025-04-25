/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:41:18 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/10 14:52:02 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_data;
	unsigned char	*s2_data;

	i = 0;
	s1_data = (unsigned char *)s1;
	s2_data = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1_data[i] != s2_data[i])
			return (s1_data[i] - s2_data[i]);
		++i;
	}
	return (0);
}
