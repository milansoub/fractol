/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:40:42 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/15 11:41:58 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	get_next_percent_index(const char *s, int current_index)
{
	int		i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == '%')
			return (current_index + i);
		++i;
	}
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		next_percent;
	int		next_size;
	int		total_size;
	va_list	list;

	i = 0;
	if (s == NULL)
		return (-1);
	total_size = 0;
	va_start(list, s);
	next_percent = get_next_percent_index(s, i);
	while (next_percent != -1)
	{
		next_size = next_percent - i;
		write(1, s + i, next_size);
		total_size += next_size;
		i += next_size + 2;
		total_size += process_param(s + next_percent, &list);
		next_percent = get_next_percent_index(s + i, i);
	}
	va_end(list);
	write(1, s + i, ft_strlen(s + i));
	total_size += ft_strlen(s + i);
	return (total_size);
}
