/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:28:42 by msoubrou          #+#    #+#             */
/*   Updated: 2024/01/31 13:58:39 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <math.h>

void	init_mandelbrot(t_fractol *frac)
{
	frac->ctx->renderer = mandelbrot_renderer;
	frac->ctx->range_x = (t_range){-2, 2};
	frac->ctx->range_y = (t_range){-2, 2};
	frac->ctx->max_iter = 80;
}

static t_rgb	periodic_colors(double x)
{
	t_rgb	rgb;
	double	a;
	double	b;
	double	c;

	a = 1 * (1 / log(2));
	b = (1 / (3 * sqrt(2))) * (1 / log(2));
	c = (1 / (1.28208068524 * (1 / log(2))));
	rgb.r = 255 * ((1 - cos(a * x)) / 2);
	rgb.g = 255 * ((1 - cos(b * x)) / 2);
	rgb.b = 255 * ((1 - cos(c * x)) / 2);
	return (rgb);
}

static void	process_pixel(t_fractol *frac, int x, int y)
{
	int		i;
	double	tmp_x;
	t_rgb	rgb;

	frac->ctx->c.r = frac->ctx->offset_x + ft_mapf((t_range){0, frac->width},
			scaled_range(&frac->ctx->range_x, frac->ctx->scale), x);
	frac->ctx->c.i = frac->ctx->offset_y + ft_mapf((t_range){0, frac->height},
			scaled_range(&frac->ctx->range_y, frac->ctx->scale), y);
	frac->ctx->z.r = 0;
	frac->ctx->z.i = 0;
	i = 0;
	while (i < frac->ctx->max_iter && abs_cmplx(&frac->ctx->z) <= 2)
	{
		tmp_x = frac->ctx->z.r;
		frac->ctx->z.r = sqr_cmplx(&frac->ctx->z) + frac->ctx->c.r;
		frac->ctx->z.i = 2 * tmp_x * frac->ctx->z.i + frac->ctx->c.i;
		++i;
	}
	rgb = periodic_colors(i);
	mlx_put_pixel(frac->img, x, y, rgb_s_to_hex(&rgb, 255));
}

void	mandelbrot_renderer(t_fractol *frac)
{
	int		x;
	int		y;

	frac->ctx->rendering = true;
	clear_window(frac);
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			process_pixel(frac, x, y);
			y += frac->ctx->pixel_odd;
		}
		x += frac->ctx->pixel_odd;
	}
	mlx_image_to_window(frac->mlx, frac->img, 0, 0);
	frac->ctx->rendering = false;
}
