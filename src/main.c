/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:22:07 by msoubrou          #+#    #+#             */
/*   Updated: 2024/01/31 13:34:32 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

bool	init_mlx(mlx_t **mlx, mlx_image_t **img)
{
	*mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "fractol", false);
	if (!*mlx)
	{
		perr("Failed to load mlx...");
		return (false);
	}
	*img = mlx_new_image(*mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!*img)
	{
		mlx_terminate(*mlx);
		perr("Failed to create image...");
		return (false);
	}
	return (true);
}

void	init_ctx(t_fractol *frac)
{
	frac->width = WIN_WIDTH;
	frac->height = WIN_HEIGHT;
	frac->ctx->rendering = false;
	frac->ctx->scale = 1;
	frac->ctx->offset_x = 0;
	frac->ctx->offset_y = 0;
	frac->ctx->pixel_odd = 1;
	frac->ctx->zoom_c = 1;
}

int	main(int ac, char **av)
{
	t_fractol	fractol;
	t_ctx		ctx;

	fractol.ctx = &ctx;
	if (!get_ctx(&fractol, ac, av))
	{
		perr("Invalid input...");
		print_help();
		return (1);
	}
	init_ctx(&fractol);
	if (!init_mlx(&fractol.mlx, &fractol.img))
		return (1);
	mlx_key_hook(fractol.mlx, handle_input, &fractol);
	mlx_scroll_hook(fractol.mlx, handle_scroll, &fractol);
	mlx_mouse_hook(fractol.mlx, handle_mouse, &fractol);
	fractol.ctx->renderer(&fractol);
	mlx_loop(fractol.mlx);
	mlx_delete_image(fractol.mlx, fractol.img);
	mlx_terminate(fractol.mlx);
	return (0);
}
