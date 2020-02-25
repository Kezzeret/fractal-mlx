/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:45:52 by jkimberl          #+#    #+#             */
/*   Updated: 2019/10/13 19:45:53 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_menu(t_fractol *fract)
{
	mlx_string_put(fract->mlx, fract->window, 2170, 1230, 16777215,
		"Zoom          - Scroll");
	mlx_string_put(fract->mlx, fract->window, 2170, 1250, 16777215,
		"Iterations    - +/-");
	mlx_string_put(fract->mlx, fract->window, 2170, 1270, 16777215,
		"Move          - Arrows");
	mlx_string_put(fract->mlx, fract->window, 2130, 1290, 16777215,
		"Start/Stop julia's K change  - K");
}

int				main(int argc, char **argv)
{
	t_fractol	*fractol;
	int			n;

	if (argc != 2)
	{
		ft_putstr("usage: [fractal]\n");
		exit(1);
	}
	if (!(ft_strcmp(argv[1], "julia")))
		n = 2;
	else if (!(ft_strcmp(argv[1], "mandelbrot")))
		n = 1;
	else if (!(ft_strcmp(argv[1], "mandelbar")))
		n = 3;
	else
	{
		ft_putstr("Error. Available fractals: \"julia\" ");
		ft_putstr(",\"mandelbrot\", \"mandelbar\"\n");
		exit(1);
	}
	fractol = init_fractol(n);
	draw_right(fractol);
	draw_fractal(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
