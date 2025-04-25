/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:37:20 by msoubrou          #+#    #+#             */
/*   Updated: 2024/01/26 16:00:28 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double	sqr_cmplx(t_complex *z)
{
	return (z->r * z->r - z->i * z->i);
}

double	abs_cmplx(t_complex *z)
{
	return (sqrt(pow(z->r, 2) + pow(z->i, 2)));
}

void	add_cmplx(t_complex *a, t_complex *b)
{
	a->r += b->r;
	a->i += b->i;
}

double	ft_mapf(t_range in, t_range out, double val)
{
	return ((val - in.min) * (out.max - out.min) / (in.max - in.min) + out.min);
}

void	perr(const char *err)
{
	if (!err)
		return ;
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
}
