/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:13:26 by lde-taey          #+#    #+#             */
/*   Updated: 2024/05/15 16:14:24 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fract *f, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}

// key events
int	key_event(int keycode, t_fract *fractal)
{
	if (keycode == KEY_ESC)
		clean_exit(0, fractal);
	if (keycode == KEY_UP)
		fractal->shift_y -= (0.2 * (fractal->max_r - fractal->min_r));
	else if (keycode == KEY_DOWN)
		fractal->shift_y += (0.2 * (fractal->max_r - fractal->min_r));
	else if (keycode == KEY_LEFT)
		fractal->shift_x -= (0.2 * (fractal->max_r - fractal->min_r));
	else if (keycode == KEY_RIGHT)
		fractal->shift_x += (0.2 * (fractal->max_r - fractal->min_r));
	else if (keycode == KEY_PLUS)
		fractal->max_iterations += 50;
	else if (keycode == KEY_MINUS)
		fractal->max_iterations -= 50;
	else
		return (-1);
	render_fract(fractal);
	return (0);
}

// mouse events 
int	mouse_event(int keycode, int x, int y, t_fract *fractal)
{
	if (keycode == MOUSE_WHEEL_UP)
		zoom(fractal, 0.5);
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(fractal, 2);
	else
		return (-1);
	x = x + 0;
	y = y + 0;
	render_fract(fractal);
	return (0);
}
