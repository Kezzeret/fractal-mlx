/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:46:03 by jkimberl          #+#    #+#             */
/*   Updated: 2019/10/13 19:46:04 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void			change_fractol(int x, int y, t_fractol *fractol)
{
	if (x >= 2000)
	{
		if (y < 400)
		{
			set_defaults(fractol);
			fractol->n = 1;
			draw_fractal(fractol);
		}
		if (y >= 400 && y < 800)
		{
			set_defaults(fractol);
			fractol->n = 2;
			draw_fractal(fractol);
		}
		if (y >= 800 && y < 1200)
		{
			set_defaults(fractol);
			fractol->n = 3;
			draw_fractal(fractol);
		}
	}
}

void			zoom(int button, int x, int y, t_fractol *fractol)
{
	double		interpolation;
	t_complex	mouse;
	double		zoom;

	mouse = init_complex(
			(double)x / (WIDTH / (fractol->max.re - fractol->min.re))
			+ fractol->min.re,
			(double)y / (HEIGHT / (fractol->max.im - fractol->min.im))
			* -1 + fractol->max.im);
	if (button == MOUSE_SCROLL_DOWN)
		zoom = 0.9;
	else
		zoom = 1.10;
	interpolation = 1.0 / zoom;
	fractol->min.re = interpolate(mouse.re, fractol->min.re, interpolation);
	fractol->min.im = interpolate(mouse.im, fractol->min.im, interpolation);
	fractol->max.re = interpolate(mouse.re, fractol->max.re, interpolation);
	fractol->max.im = interpolate(mouse.im, fractol->max.im, interpolation);
	draw_fractal(fractol);
}

int				mouse_press(int button, int x, int y, t_fractol *fractol)
{
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, x, y, fractol);
	if (button == 1)
		change_fractol(x, y, fractol);
	return (0);
}

int				julia_motion(int x, int y, t_fractol *fractol)
{
	if (!fractol->is_julia_fixed && fractol->n == 2)
	{
		fractol->k = init_complex(
			4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fractal(fractol);
	}
	return (0);
}
