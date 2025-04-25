/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:13:21 by msoubrou          #+#    #+#             */
/*   Updated: 2024/01/31 14:12:52 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <unistd.h>

void	print_help(void)
{
	ft_printf("\e[1;93m---------------\e[0m\n\
Available Sets:\n\n\e[1;36m mandelbrot \e[0m\nparams: none\n\n\
\e[1;35m julia \e[0m\n\
params: constant C <a> <b>\n\n\
\e[1;31m burning_ship \e[0m\nparams: none\n\
\e[1;93m---------------\e[0m\n");
}

static bool	julia_args(t_fractol *frac, int ac, char **av)
{
	double	res;
	int		error;

	if (ac < 4)
		return (false);
	error = 0;
	res = ft_atof(av[2], &error);
	if (error)
		return (false);
	frac->ctx->c.r = res;
	res = ft_atof(av[3], &error);
	if (error)
		return (false);
	frac->ctx->c.i = res;
	return (true);
}

bool	get_ctx(t_fractol *frac, int ac, char **av)
{
	if (ac < 2)
		return (false);
	if (ft_strncmp(av[1], "julia", 5) == 0)
	{
		if (!julia_args(frac, ac, av))
		{
			perr("reading failed...");
			return (false);
		}
		init_julia(frac);
	}
	else if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
		init_mandelbrot(frac);
	else if (ft_strncmp(av[1], "burning_ship", 12) == 0)
		init_burning_ship(frac);
	else
		return (false);
	return (true);
}
