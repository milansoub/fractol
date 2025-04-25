/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:21:39 by msoubrou          #+#    #+#             */
/*   Updated: 2024/01/31 13:55:29 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# ifndef WIN_WIDTH
#  define WIN_WIDTH 800
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 800
# endif

typedef unsigned char	t_uc;
typedef modifier_key_t	t_mod;
typedef mouse_key_t		t_mkey;
struct					s_fractol;

typedef struct s_rgb
{
	char	r;
	char	g;
	char	b;
}	t_rgb;

typedef struct s_range
{
	double	min;
	double	max;
}	t_range;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_draw_context
{
	t_complex	z;
	t_complex	c;
	int			max_iter;
	double		scale;
	t_range		range_x;
	t_range		range_y;
	double		offset_x;
	double		offset_y;
	int			pixel_odd;
	int			zoom_c;
	bool		rendering;

	void		(*renderer)(struct s_fractol*);
}	t_ctx;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_ctx		*ctx;
	int			width;
	int			height;
}	t_fractol;

bool		get_ctx(t_fractol *frac, int ac, char **av);
void		print_help(void);

void		init_burning_ship(t_fractol *frac);
void		init_julia(t_fractol *frac);
void		init_mandelbrot(t_fractol *frac);
void		burning_ship_renderer(t_fractol *fractol);
void		julia_renderer(t_fractol *fractol);
void		mandelbrot_renderer(t_fractol *fractol);

void		handle_input(mlx_key_data_t data, void *frac);
void		handle_scroll(double xdelta, double ydelta, void *data);
void		handle_mouse(t_mkey b, action_t a, t_mod m, void *frac);
void		zoom(t_fractol *frac);
t_range		scaled_range(t_range *range, double scale);
double		squared_modulus(t_complex *z);
double		sqr_cmplx(t_complex *z);
double		abs_cmplx(t_complex *z);
void		add_cmplx(t_complex *a, t_complex *b);
double		abs_d(double n);
double		ft_mapf(t_range in, t_range out, double val);
void		perr(const char *err);
double		ft_atof(const char *str, int *error);
int			check_atof(const char *str);
void		add_atof_res(double *res, int64_t int_res, int sign);
int			rgb_s_to_hex(t_rgb *rgb, int a);
void		clear_window(t_fractol *frac);

#endif