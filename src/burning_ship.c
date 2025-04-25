/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:12:41 by msoubrou          #+#    #+#             */
/*   Updated: 2024/01/31 13:59:22 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_burning_ship(t_fractol *frac)
{
	frac->ctx->renderer = burning_ship_renderer;
	frac->ctx->max_iter = 100;
	frac->ctx->range_x = (t_range){-2.5, 2};
	frac->ctx->range_y = (t_range){-2, 1};
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
		tmp_x = frac->ctx->z.r * frac->ctx->z.r - frac->ctx->z.i
			* frac->ctx->z.i + frac->ctx->c.r;
		frac->ctx->z.i = abs_d(2 * frac->ctx->z.r * frac->ctx->z.i)
			+ frac->ctx->c.i;
		frac->ctx->z.r = tmp_x;
		++i;
	}
	rgb.r = 255 * ((((i + 1) - log(log2(abs_cmplx(&frac->ctx->z))))));
	rgb.g = 128 * i / frac->ctx->max_iter;
	rgb.b = 255 * i / frac->ctx->max_iter;
	mlx_put_pixel(frac->img, x, y, rgb_s_to_hex(&rgb, 255));
}

void	burning_ship_renderer(t_fractol *frac)
{
	int		x;
	int		y;

	frac->ctx->rendering = true;
	clear_window(frac);
	x = 0;
	while (x < frac->width)
	{
		y = 0;
		while (y < frac->height)
		{
			process_pixel(frac, x, y);
			y += frac->ctx->pixel_odd;
		}
		x += frac->ctx->pixel_odd;
	}
	mlx_image_to_window(frac->mlx, frac->img, 0, 0);
	frac->ctx->rendering = false;
}
