/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:03:02 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 12:54:48 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_l;
	size_t	dst_l;

	i = 0;
	src_l = ft_strlen(src);
	if (size == 0)
		return (src_l);
	dst_l = ft_strlen(dst);
	if (size <= dst_l)
		return (size + src_l);
	while (i + dst_l < size - 1 && i < src_l)
	{
		dst[i + dst_l] = src[i];
		++i;
	}
	dst[i + dst_l] = 0;
	return (dst_l + src_l);
}
