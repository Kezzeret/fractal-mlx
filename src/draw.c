/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:39:21 by jkimberl          #+#    #+#             */
/*   Updated: 2019/10/13 18:39:24 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

void			put_pxl_to_img(t_fractol *data, int x, int y, int color)
{
	if (x < WIDTH && y < WIDTH)
	{
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4, &color, sizeof(int));
	}
}

static void		mandelbar(t_fractol *fract)
{
	int			x;
	int			y;
	int			iteration;
	t_complex	z;
	int			color;

	y = fract->start_line;
	while (y < fract->finish_line)
	{
		fract->c.im = (fract->max.im - y * fract->factor.im);
		x = 0;
		while (x < WIDTH)
		{
			fract->c.re = (fract->min.re + x * fract->factor.re);
			z = init_complex(fract->c.re, fract->c.im);
			iteration = mandelbar_extra(z, fract);
			color = get_color(iteration, fract);
			put_pxl_to_img(fract, x, y, color);
			x++;
		}
		y++;
	}
}

static void		mandelbrot(t_fractol *fract)
{
	int			x;
	int			y;
	int			iteration;
	t_complex	z;
	int			color;

	y = fract->start_line;
	while (y < fract->finish_line)
	{
		fract->c.im = (fract->max.im - y * fract->factor.im);
		x = 0;
		while (x < WIDTH)
		{
			fract->c.re = (fract->min.re + x * fract->factor.re);
			z = init_complex(fract->c.re, fract->c.im);
			iteration = mandelbrot_extra(z, fract);
			color = get_color(iteration, fract);
			put_pxl_to_img(fract, x, y, color);
			x++;
		}
		y++;
	}
}

static void		julia(t_fractol *fract)
{
	int			x;
	int			y;
	int			iteration;
	t_complex	z;
	int			color;

	y = fract->start_line;
	while (y < fract->finish_line)
	{
		fract->c.im = (fract->max.im - y * fract->factor.im);
		x = 0;
		while (x < WIDTH)
		{
			fract->c.re = (fract->min.re + x * fract->factor.re);
			z = init_complex(fract->c.re, fract->c.im);
			iteration = julia_extra(z, fract);
			color = get_color(iteration, fract);
			put_pxl_to_img(fract, x, y, color);
			x++;
		}
		y++;
	}
}

void			draw_fractal(t_fractol *fractol)
{
	t_fractol	tab[THREADS];
	pthread_t	t[THREADS];
	int			i;

	fractol->factor = init_complex(
			(fractol->max.re - fractol->min.re) / (WIDTH - 1),
			(fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	i = 0;
	while (i < THREADS)
	{
		tab[i] = *fractol;
		tab[i].start_line = i * (HEIGHT / THREADS);
		tab[i].finish_line = (i + 1) * (HEIGHT / THREADS);
		if (fractol->n == 2)
			pthread_create(&t[i], NULL, (void *)julia, (void *)&tab[i]);
		if (fractol->n == 1)
			pthread_create(&t[i], NULL, (void *)mandelbrot, (void *)&tab[i]);
		if (fractol->n == 3)
			pthread_create(&t[i], NULL, (void *)mandelbar, (void *)&tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->img, 0, 0);
}
