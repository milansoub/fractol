/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:22:00 by msoubrou          #+#    #+#             */
/*   Updated: 2024/01/30 14:15:21 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_julia(t_fractol *frac)
{
	frac->ctx->renderer = julia_renderer;
	frac->ctx->range_x = (t_range){-1.5, 1.5};
	frac->ctx->range_y = (t_range){-1.5, 1.5};
	frac->ctx->max_iter = 310;
}

void	process_pixel(t_fractol *frac, int x, int y, double abs_max)
{
	int		i;
	double	tmp_x;
	t_rgb	rgb;

	frac->ctx->z.r = frac->ctx->offset_x + ft_mapf((t_range){0, frac->width},
			scaled_range(&frac->ctx->range_x, frac->ctx->scale), x);
	frac->ctx->z.i = frac->ctx->offset_y + ft_mapf((t_range){0, frac->height},
			scaled_range(&frac->ctx->range_y, frac->ctx->scale), y);
	i = 0;
	while (i < frac->ctx->max_iter && abs_cmplx(&frac->ctx->z) <= abs_max)
	{
		tmp_x = frac->ctx->z.r;
		frac->ctx->z.r = sqr_cmplx(&frac->ctx->z) + frac->ctx->c.r;
		frac->ctx->z.i = 2 * tmp_x * frac->ctx->z.i + frac->ctx->c.i;
		++i;
	}
	rgb.r = 255 * i / frac->ctx->max_iter;
	rgb.g = 4 * i;
	rgb.b = (i - 1) * log(log2(abs_cmplx(&frac->ctx->z))) / 2;
	mlx_put_pixel(frac->img, x, y, rgb_s_to_hex(&rgb, 255));
}

void	julia_renderer(t_fractol *frac)
{
	int		x;
	int		y;
	double	abs_max;

	frac->ctx->rendering = true;
	clear_window(frac);
	abs_max = 10;
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			process_pixel(frac, x, y, abs_max);
			y += frac->ctx->pixel_odd;
		}
		x += frac->ctx->pixel_odd;
	}
	mlx_image_to_window(frac->mlx, frac->img, 0, 0);
	frac->ctx->rendering = false;
}
