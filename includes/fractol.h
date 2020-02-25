/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:51:18 by jkimberl          #+#    #+#             */
/*   Updated: 2019/10/13 19:51:22 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH		2000
# define HEIGHT		1440

# define THREADS	40

# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdint.h>
# include <stdlib.h>

typedef	struct		s_color
{
	int8_t			channel[4];
}					t_color;

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_fractol
{
	void			*mlx;
	void			*window;
	void			*img;
	void			*img_ptr;
	void			*img_1;
	void			*img_ptr_1;
	int				endian;
	int				sl;
	int				bpp;
	int				n;
	int				max_iteration;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	int				is_julia_fixed;
	int				start_line;
	int				finish_line;
}					t_fractol;

t_complex			init_complex(double re, double im);

void				set_defaults(t_fractol *fractol);
void				draw_fractal(t_fractol *fractol);
void				put_pxl_to_img(t_fractol *data, int x, int y, int color);
int					get_color(int iteration, t_fractol *fractol);
int					key_press(int key, t_fractol *fractol);
int					mouse_press(int button, int x, int y, t_fractol *fractol);
int					julia_motion(int x, int y, t_fractol *fractol);
void				zoom(int button, int x, int y, t_fractol *fractol);
int					change_frac(int button, int x, int y, t_fractol *fractol);
t_fractol			*init_fractol(int n);
void				draw_right(t_fractol *fractol);
int					julia_extra(t_complex z, t_fractol *fractol);
int					mandelbrot_extra(t_complex z, t_fractol *fractol);
int					mandelbar_extra(t_complex z, t_fractol *fractol);
void				draw_menu(t_fractol *fract);

#endif
