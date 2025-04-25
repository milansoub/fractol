/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mily <mily@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:57:08 by msoubrou          #+#    #+#             */
/*   Updated: 2024/01/29 19:40:08 by mily             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	rgb_s_to_hex(t_rgb *rgb, int a)
{
	int	res;

	res = rgb->r;
	res = (res << 8) | rgb->g;
	res = (res << 8) | rgb->b;
	res = (res << 8) | a;
	return (res);
}

double	squared_modulus(t_complex *z)
{
	return (z->i * z->i - z->i * z->i);
}

t_range	scaled_range(t_range *r, double scale)
{
	return ((t_range){r->min * scale, r->max * scale});
}

void	clear_window(t_fractol *frac)
{
	int	x;
	int	y;

	x = 0;
	while (x < frac->width)
	{
		y = 0;
		while (y < frac->height)
		{
			mlx_put_pixel(frac->img, x, y, 0);
			++y;
		}
		++x;
	}
}

double	abs_d(double n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
