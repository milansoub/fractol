/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:11:04 by msoubrou          #+#    #+#             */
/*   Updated: 2024/01/31 13:29:47 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	zoom(t_fractol *frac)
{
	int	x;
	int	y;

	mlx_get_mouse_pos(frac->mlx, &x, &y);
	frac->ctx->offset_x += ft_mapf((t_range){0, frac->width},
			scaled_range(&frac->ctx->range_x, frac->ctx->scale), (double)x);
	frac->ctx->offset_y += ft_mapf((t_range){0, frac->height},
			scaled_range(&frac->ctx->range_y, frac->ctx->scale), (double)y);
	frac->ctx->zoom_c++;
}

static void	handle_iter(mlx_key_data_t data, t_fractol *frac)
{
	if (data.key == MLX_KEY_J
		&& data.action == MLX_PRESS)
	{
		if (data.modifier == MLX_CONTROL)
			frac->ctx->max_iter--;
		else
			frac->ctx->max_iter -= 10;
		if (frac->ctx->max_iter < 1)
			frac->ctx->max_iter = 1;
		ft_printf("Max iter: %d\n", frac->ctx->max_iter);
	}
	else if (data.key == MLX_KEY_K
		&& data.action == MLX_PRESS)
	{
		if (data.modifier == MLX_CONTROL)
			frac->ctx->max_iter++;
		else
			frac->ctx->max_iter += 10;
		if (frac->ctx->max_iter > 1000000)
			frac->ctx->max_iter = 1;
		ft_printf("Max iter: %d\n", frac->ctx->max_iter);
	}
}

static void	handle_keys(mlx_key_data_t data, t_fractol *frac)
{
	if (data.key == MLX_KEY_UP
		&& data.action == MLX_RELEASE)
		frac->ctx->offset_y -= 0.25 * frac->ctx->scale;
	else if (data.key == MLX_KEY_LEFT
		&& data.action == MLX_RELEASE)
		frac->ctx->offset_x -= 0.25 * frac->ctx->scale;
	else if (data.key == MLX_KEY_DOWN
		&& data.action == MLX_RELEASE)
		frac->ctx->offset_y += 0.25 * frac->ctx->scale;
	else if (data.key == MLX_KEY_RIGHT
		&& data.action == MLX_RELEASE)
		frac->ctx->offset_x += 0.25 * frac->ctx->scale;
	handle_iter(data, frac);
}

void	handle_input(mlx_key_data_t data, void *fractol)
{
	t_fractol	*frac;

	frac = fractol;
	if (data.key == MLX_KEY_ESCAPE)
		mlx_close_window(frac->mlx);
	else if (data.key == MLX_KEY_N && data.action == MLX_RELEASE)
	{
		if (frac->ctx->pixel_odd > 1)
		{
			frac->ctx->pixel_odd--;
			ft_printf("Pixel Odds: %d\n", frac->ctx->pixel_odd);
		}
	}
	else if (data.key == MLX_KEY_B && data.action == MLX_RELEASE)
	{
		if (frac->ctx->pixel_odd < 6)
		{
			frac->ctx->pixel_odd++;
			ft_printf("Pixel Odds: %d\n", frac->ctx->pixel_odd);
		}
	}
	else if (data.key == MLX_KEY_R && data.action == MLX_RELEASE
		&& !frac->ctx->rendering)
		frac->ctx->renderer(frac);
	handle_keys(data, frac);
}

void	handle_mouse(t_mkey button, action_t action, t_mod mods, void *fractol)
{
	t_fractol	*frac;

	frac = fractol;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_RELEASE
		&& !frac->ctx->rendering)
	{
		if (mods == MLX_CONTROL)
			frac->ctx->scale *= 0.5;
		else
			frac->ctx->scale *= 0.75;
		zoom(frac);
		frac->ctx->renderer(frac);
	}
	else if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_RELEASE
		&& !frac->ctx->rendering)
	{
		if (mods == MLX_CONTROL)
			frac->ctx->scale *= 1.5;
		else
			frac->ctx->scale *= 1.25;
		frac->ctx->zoom_c--;
		frac->ctx->renderer(frac);
	}
}
