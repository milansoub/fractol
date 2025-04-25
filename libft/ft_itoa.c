/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:53:11 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 12:50:56 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <malloc.h>
#include <limits.h>

static	int	allocate_str(int n, char **str)
{
	int		size;

	size = 0;
	if (n == 0)
		size = 1;
	if (n < 0)
	{
		++size;
		n *= -1;
	}
	while (n != 0)
	{
		++size;
		n /= 10;
	}
	*str = malloc(size + 1);
	return (size);
}

static void	rec_itoa(int n, char *s, int index)
{
	if (n != 0)
	{
		rec_itoa(n / 10, s, index - 1);
		s[index] = n % 10 + 48;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = allocate_str(n, &str);
	if (str == NULL)
		return (NULL);
	str[size] = 0;
	if (n == 0)
		str[0] = '0';
	else if (n == INT_MIN)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	rec_itoa(n, str, size - 1);
	return (str);
}
