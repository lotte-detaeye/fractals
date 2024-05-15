/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:47:43 by lde-taey          #+#    #+#             */
/*   Updated: 2024/05/14 14:43:17 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_exit(int exit_code, t_fract *fractal)
{
	if (!fractal)
		exit(exit_code);
	if (fractal->imag.img_ptr)
		mlx_destroy_image(fractal->mlx_con, fractal->imag.img_ptr);
	if (fractal->mlx_win && fractal->mlx_con)
		mlx_destroy_window(fractal->mlx_con, fractal->mlx_win);
	if (fractal->mlx_con)
	{
		mlx_loop_end(fractal->mlx_con);
		mlx_destroy_display(fractal->mlx_con);
		free(fractal->mlx_con);
	}
	exit(exit_code);
}

int	close_event(t_fract *fractal)
{
	if (!fractal)
		exit(-1);
	if (fractal->imag.img_ptr)
		mlx_destroy_image(fractal->mlx_con, fractal->imag.img_ptr);
	if (fractal->mlx_win && fractal->mlx_con)
		mlx_destroy_window(fractal->mlx_con, fractal->mlx_win);
	if (fractal->mlx_con)
	{
		mlx_loop_end(fractal->mlx_con);
		mlx_destroy_display(fractal->mlx_con);
		free(fractal->mlx_con);
	}
	exit(0);
}
