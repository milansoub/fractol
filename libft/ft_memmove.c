/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:08:01 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/10 14:50:46 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_block;
	unsigned char	*src_block;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest_block = dest;
	src_block = (unsigned char *)src;
	if (src < dest)
	{
		i = n;
		while (i-- > 0)
			dest_block[i] = src_block[i];
		return (dest);
	}
	while (i < n)
	{
		dest_block[i] = src_block[i];
		++i;
	}
	return (dest);
}
