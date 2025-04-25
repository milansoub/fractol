/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:25:16 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/15 11:42:16 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	rec_print_uint(unsigned int n)
{
	int	len;

	if (n != 0)
	{
		len = rec_print_uint(n / 10) + 1;
		ft_putchar_fd(n % 10 + 48, 1);
		return (len);
	}
	return (0);
}

int	ft_print_uint(unsigned int n)
{
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	return (rec_print_uint(n));
}
