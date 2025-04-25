/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:48:01 by msoubrou          #+#    #+#             */
/*   Updated: 2024/01/31 13:55:09 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	add_atof_res(double *res, int64_t int_res, int sign)
{
	*res += int_res;
	*res *= sign;
}

int	check_atof(const char *str)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (1);
		else if (str[i] == '.')
			found++;
		++i;
	}
	if (found > 1)
		return (1);
	return (0);
}
