/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:59:34 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/10 14:49:33 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_block;
	unsigned char	*src_block;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest_block = dest;
	src_block = (unsigned char *)src;
	while (i < n)
	{
		dest_block[i] = src_block[i];
		++i;
	}
	return (dest);
}
