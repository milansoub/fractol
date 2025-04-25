/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:10:13 by msoubrou          #+#    #+#             */
/*   Updated: 2024/01/31 13:55:45 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	count_decimals(const char *str, int *error)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] != '.')
		return (0);
	++i;
	while (str[i] && ft_isdigit(str[i]))
	{
		++i;
		++count;
	}
	if (count > 10)
		*error = 1;
	return (count);
}

static int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n'
		|| str[i] == '\t' || str[i] == '\v')
		++i;
	return (i);
}

static int	get_sign(const char *str, int *i)
{
	if (str[*i] == '-')
	{
		*i += 1;
		return (-1);
	}
	else if (str[*i] == '+')
	{
		*i += 1;
		return (1);
	}
	return (1);
}

static double	get_decimals(const char *str, int i, int *error)
{
	int		j;
	int		count;
	double	res;

	count = count_decimals(str + i, error);
	if (!count || *error)
		return (0);
	++i;
	j = 0;
	res = 0;
	while (j < count)
	{
		res *= 10;
		res += str[i] - 48;
		++i;
		++j;
	}
	res /= pow(10, count);
	return (res);
}

double	ft_atof(const char *str, int *error)
{
	double	res;
	int64_t	int_res;
	int		i;
	int		sign;

	*error = check_atof(str);
	if (*error)
		return (0);
	int_res = 0;
	i = ft_isspace(str);
	sign = get_sign(str, &i);
	while (str[i] && ft_isdigit(str[i]))
	{
		int_res *= 10;
		int_res += str[i] - 48;
		if (int_res > INT32_MAX)
		{
			*error = 1;
			return (0);
		}
		++i;
	}
	res = get_decimals(str, i, error);
	add_atof_res(&res, int_res, sign);
	return (res);
}
