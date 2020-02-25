/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:45:11 by jkimberl          #+#    #+#             */
/*   Updated: 2019/10/13 19:45:13 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_extra(t_complex z, t_fractol *fract)
{
	int	iteration;

	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fract->max_iteration)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + fract->k.re,
			2.0 * z.re * z.im + fract->k.im);
		iteration++;
	}
	return (iteration);
}

int		mandelbrot_extra(t_complex z, t_fractol *fract)
{
	int	iteration;

	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fract->max_iteration)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + fract->c.re,
			2.0 * z.re * z.im + fract->c.im);
		iteration++;
	}
	return (iteration);
}

int		mandelbar_extra(t_complex z, t_fractol *fract)
{
	int	iteration;

	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fract->max_iteration)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + fract->c.re,
			-2.0 * z.re * z.im + fract->c.im);
		iteration++;
	}
	return (iteration);
}
