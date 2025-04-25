/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:46:20 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/15 11:59:26 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	rec_print_hex(char base[17], unsigned int n)
{
	int	len;

	if (n != 0)
	{
		len = rec_print_hex(base, n / 16) + 1;
		ft_putchar_fd(base[n % 16], 1);
		return (len);
	}
	return (0);
}

int	ft_print_hex(unsigned int n, char upper)
{
	int		len;

	len = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (!upper)
		len += rec_print_hex(LOWER_HEX, n);
	else
		len += rec_print_hex(UPPER_HEX, n);
	return (len);
}
