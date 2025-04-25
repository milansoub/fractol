/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:02:54 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/15 11:43:56 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <malloc.h>

int	process_int(va_list *list)
{
	int		n;
	char	*str;
	int		len;

	n = va_arg(*list, int);
	str = ft_itoa(n);
	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int	process_uint(va_list *list)
{
	unsigned int	n;

	n = va_arg(*list, unsigned int);
	return (ft_print_uint(n));
}

int	process_hex(va_list *list, char upper)
{
	int	n;

	n = va_arg(*list, unsigned int);
	return (ft_print_hex(n, upper));
}

int	process_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
