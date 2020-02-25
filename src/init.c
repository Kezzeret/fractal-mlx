/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:45:26 by jkimberl          #+#    #+#             */
/*   Updated: 2019/10/13 19:45:28 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void		set_defaults(t_fractol *fractol)
{
	fractol->max_iteration = 50;
	fractol->min.re = -2.0;
	fractol->min.im = -0.5 * 4 * HEIGHT / WIDTH;
	fractol->max.re = 2.0;
	fractol->max.im = 0.5 * 4 * HEIGHT / WIDTH;
	fractol->k = init_complex(-0.4, 0.6);
}

t_fractol	*init_fractol(int n)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		exit(0);
	fractol->mlx = mlx_init();
	if (!(fractol->window = mlx_new_window(fractol->mlx,
			WIDTH + 560, HEIGHT, "fractol")))
		exit(0);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img_ptr = mlx_get_data_addr(fractol->img,
			&fractol->bpp, &fractol->sl, &fractol->endian);
	fractol->img_1 = mlx_new_image(fractol->mlx, WIDTH + 560, HEIGHT);
	fractol->img_ptr_1 = mlx_get_data_addr(fractol->img_1,
			&fractol->bpp, &fractol->sl, &fractol->endian);
	set_defaults(fractol);
	fractol->n = n;
	fractol->is_julia_fixed = 1;
	mlx_hook(fractol->window, 2, 0, key_press, fractol);
	mlx_hook(fractol->window, 4, 0, mouse_press, fractol);
	mlx_hook(fractol->window, 6, 0, julia_motion, fractol);
	return (fractol);
}
