/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:45:39 by jkimberl          #+#    #+#             */
/*   Updated: 2019/10/13 19:45:41 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

static void		move(int key, t_fractol *fractol)
{
	t_complex	d;

	d = init_complex(FT_ABS(fractol->max.re - fractol->min.re),
		FT_ABS(fractol->max.im - fractol->min.im));
	if (key == ARROW_LEFT)
	{
		fractol->min.re = fractol->min.re - d.re * 0.1;
		fractol->max.re = fractol->max.re - d.re * 0.1;
	}
	else if (key == ARROW_RIGHT)
	{
		fractol->min.re = fractol->min.re + d.re * 0.1;
		fractol->max.re = fractol->max.re + d.re * 0.1;
	}
	else if (key == ARROW_UP)
	{
		fractol->min.im = fractol->min.im + d.im * 0.1;
		fractol->max.im = fractol->max.im + d.im * 0.1;
	}
	else if (key == ARROW_DOWN)
	{
		fractol->min.im = fractol->min.im - d.im * 0.1;
		fractol->max.im = fractol->max.im - d.im * 0.1;
	}
	draw_fractal(fractol);
}

static void		change_max_iteration(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_PLUS)
	{
		if (fractol->max_iteration < 50)
			fractol->max_iteration += 1;
		else if (fractol->max_iteration < 1000000000)
			fractol->max_iteration = (int)(fractol->max_iteration * 1.05);
	}
	if (key == MAIN_PAD_MINUS)
	{
		if (fractol->max_iteration > 50)
			fractol->max_iteration = (int)(fractol->max_iteration * 0.95);
		else if (fractol->max_iteration > 1)
			fractol->max_iteration -= 1;
	}
	draw_fractal(fractol);
}

int				key_press(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	else if (key == MAIN_PAD_MINUS || key == MAIN_PAD_PLUS)
		change_max_iteration(key, fractol);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_UP || key == ARROW_DOWN)
		move(key, fractol);
	else if (key == MAIN_PAD_K)
		fractol->is_julia_fixed = !fractol->is_julia_fixed;
	return (0);
}
