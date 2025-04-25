/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:40:39 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/15 11:56:19 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	process_param(const char *s, va_list *list)
{
	if (s[1] == 'c')
		return (process_char(list));
	else if (s[1] == 's')
		return (process_string(list));
	else if (s[1] == 'p')
		return (process_pointer(list));
	else if (s[1] == 'd')
		return (process_decimal(list));
	else if (s[1] == 'i')
		return (process_int(list));
	else if (s[1] == 'u')
		return (process_uint(list));
	else if (s[1] == 'x')
		return (process_hex(list, 0));
	else if (s[1] == 'X')
		return (process_hex(list, 1));
	else if (s[1] == '%')
		return (process_percent());
	else
		return (-1);
}

int	process_char(va_list *list)
{
	int	c;

	c = va_arg(*list, int);
	write(1, &c, 1);
	return (1);
}

int	process_string(va_list *list)
{
	char	*s;
	int		len;

	s = va_arg(*list, char *);
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	process_pointer(va_list *list)
{
	void	*p;

	p = va_arg(*list, void *);
	return (ft_print_pointer(p));
}

int	process_decimal(va_list *list)
{
	return (process_int(list));
}
