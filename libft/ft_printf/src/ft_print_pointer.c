/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:16:16 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/15 11:42:10 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	rec_print_pointer(size_t n, const char *base)
{
	int	len;

	if (n != 0)
	{
		len = rec_print_pointer(n / 16, base) + 1;
		ft_putchar_fd(base[n % 16], 1);
		return (len);
	}
	return (0);
}

int	ft_print_pointer(void *p)
{
	int		len;
	size_t	n;

	if (p == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	n = (size_t)p;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	len = 2;
	ft_putstr_fd("0x", 1);
	len += rec_print_pointer(n, "0123456789abcdef");
	return (len);
}
