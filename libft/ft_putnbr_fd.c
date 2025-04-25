/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:53:11 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 12:53:42 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <limits.h>

static void	rec_putnbr_fd(int n, int fd)
{
	if (n != 0)
	{
		rec_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd <= 0)
		return ;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n == INT_MIN)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		rec_putnbr_fd(n, fd);
	}
}
