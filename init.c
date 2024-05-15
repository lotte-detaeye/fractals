/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:56:59 by lde-taey          #+#    #+#             */
/*   Updated: 2024/05/15 16:12:58 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fract(t_fract *fractal)
{
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->escape_value = 4;
	fractal->max_iterations = 42;
	fractal->zoom = 1.0;
	fractal->min_r = -2.0;
	fractal->max_r = 2.0;
	fractal->max_i = -2.0;
	fractal->min_i = 2.0;
}

void	init_hooks(t_fract *fractal)
{
	mlx_hook(fractal->mlx_win,
		KeyPress,
		KeyPressMask,
		key_event,
		fractal);
	mlx_hook(fractal->mlx_win,
		ButtonPress,
		ButtonPressMask,
		mouse_event,
		fractal);
	mlx_hook(fractal->mlx_win,
		DestroyNotify,
		StructureNotifyMask,
		close_event,
		fractal);
}

void	init_mlx(t_fract *fractal)
{
	fractal->mlx_con = mlx_init(); 
	if (!fractal->mlx_con)
		clean_exit(-1, fractal);
	fractal->mlx_win = mlx_new_window(fractal->mlx_con, 
			800, 800, fractal->name);
	if (!fractal->mlx_win)
		clean_exit(-1, fractal);
	fractal->imag.img_ptr = mlx_new_image(fractal->mlx_con, 800, 800);
	if (!fractal->imag.img_ptr)
		clean_exit(-1, fractal);
	fractal->imag.pixels_ptr = mlx_get_data_addr(fractal->imag.img_ptr,
			&fractal->imag.bpp, &fractal->imag.line_len, &fractal->imag.endian);
}
