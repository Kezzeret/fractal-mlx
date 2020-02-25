/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:34:50 by jkimberl          #+#    #+#             */
/*   Updated: 2019/10/18 11:23:14 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_lines(t_fractol *fractol)
{
	int			x;
	int			y;

	x = 2000;
	y = 0;
	while (y <= 1200)
	{
		while (x <= 2560)
		{
			mlx_pixel_put(fractol->mlx, fractol->window, x, y, 16777215);
			x++;
		}
		x = 2000;
		y += 400;
	}
	y = 0;
	while (y <= 1440)
	{
		mlx_pixel_put(fractol->mlx, fractol->window, x, y, 16777215);
		y++;
	}
}

static void		draw_right_1(t_fractol *fract)
{
	int			x;
	int			y;
	int			iteration;
	t_complex	z;
	int			color;

	y = 0;
	while (y < 400)
	{
		fract->c.im = (fract->max.im - y * fract->factor.im);
		x = 2000;
		while (x < WIDTH + 560)
		{
			fract->c.re = (fract->min.re + (x - 2000) * fract->factor.re);
			z = init_complex(fract->c.re, fract->c.im);
			iteration = mandelbrot_extra(z, fract);
			color = get_color(iteration, fract);
			ft_memcpy(fract->img_ptr_1 + 4 * (WIDTH + 560) * y + x * 4,
				&color, sizeof(int));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->img_1, 0, 0);
}

static void		draw_right_2(t_fractol *fract)
{
	int			x;
	int			y;
	int			iteration;
	t_complex	z;
	int			color;

	y = 400;
	while (y < 800)
	{
		fract->c.im = (fract->max.im - (y - 400) * fract->factor.im);
		x = 2000;
		while (x < WIDTH + 560)
		{
			fract->c.re = (fract->min.re + (x - 2000) * fract->factor.re);
			z = init_complex(fract->c.re, fract->c.im);
			iteration = julia_extra(z, fract);
			color = get_color(iteration, fract);
			ft_memcpy(fract->img_ptr_1 + 4 * (WIDTH + 560) * y + x * 4,
				&color, sizeof(int));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->img_1, 0, 0);
}

static void		draw_right_3(t_fractol *fract)
{
	int			x;
	int			y;
	int			iteration;
	t_complex	z;
	int			color;

	y = 800;
	while (y < 1200)
	{
		fract->c.im = (fract->max.im - (y - 800) * fract->factor.im);
		x = 2000;
		while (x < WIDTH + 560)
		{
			fract->c.re = (fract->min.re + (x - 2000) * fract->factor.re);
			z = init_complex(fract->c.re, fract->c.im);
			iteration = mandelbar_extra(z, fract);
			color = get_color(iteration, fract);
			ft_memcpy(fract->img_ptr_1 + 4 * (WIDTH + 560) * y + x * 4,
				&color, sizeof(int));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->img_1, 0, 0);
}

void			draw_right(t_fractol *fractol)
{
	t_fractol	*frac;

	if (!(frac = (t_fractol *)malloc(sizeof(t_fractol))))
		exit(0);
	frac = fractol;
	frac->max.im = frac->min.im
		+ (frac->max.re - frac->min.re) * 400 / 560;
	frac->factor = init_complex(
		(fractol->max.re - fractol->min.re) / (560),
		(fractol->max.im - fractol->min.im) / (400));
	draw_right_1(frac);
	draw_right_2(frac);
	draw_right_3(frac);
	draw_lines(frac);
	draw_menu(frac);
	mlx_put_image_to_window(frac->mlx, frac->window, frac->img, 0, 0);
}
