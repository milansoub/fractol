/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:23:28 by msoubrou          #+#    #+#             */
/*   Updated: 2024/01/31 13:59:01 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	handle_scroll(double xdelta, double ydelta, void *data)
{
	t_fractol	*frac;

	frac = data;
	(void)xdelta;
	if (ydelta > 0)
	{
		if (mlx_is_key_down(frac->mlx, MLX_KEY_LEFT_CONTROL))
			frac->ctx->scale *= 0.5;
		else
			frac->ctx->scale *= 0.75;
		zoom(frac);
		frac->ctx->renderer(frac);
	}
	else
	{
		if (mlx_is_key_down(frac->mlx, MLX_KEY_LEFT_CONTROL))
			frac->ctx->scale *= 1.5;
		else
			frac->ctx->scale *= 1.25;
		frac->ctx->zoom_c--;
		frac->ctx->renderer(frac);
	}
}
