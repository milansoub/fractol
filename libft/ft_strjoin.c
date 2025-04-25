/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:33:49 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 12:54:36 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <malloc.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	size_t	s1_l;
	size_t	s2_l;
	size_t	buffer_size;

	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	buffer_size = s1_l + s2_l + 1;
	new_str = ft_calloc(buffer_size, 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcat(new_str, s1, buffer_size);
	ft_strlcat(new_str, s2, buffer_size);
	return (new_str);
}
