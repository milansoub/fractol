/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:34:42 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 12:49:32 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\n' || s[i] == '\r')
		++i;
	return (i);
}

static int	ft_count_digit(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0 && ft_isdigit(s[i]))
		++i;
	return (i);
}

static int	ft_pow(int n, int power)
{
	int	res;

	res = n;
	if (power == 0)
		return (1);
	while (power > 1)
	{
		res *= n;
		--power;
	}
	return (res);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;
	int	power;

	i = ft_isspace(nptr);
	res = 0;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (nptr[i] == '+')
		++i;
	power = ft_count_digit(nptr + i) - 1;
	while (nptr[i] != 0 && ft_isdigit(nptr[i]))
	{
		res += (nptr[i] - 48) * ft_pow(10, power);
		--power;
		++i;
	}
	res *= sign;
	return (res);
}
