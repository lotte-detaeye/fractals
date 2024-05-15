/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:11:40 by lde-taey          #+#    #+#             */
/*   Updated: 2024/05/15 16:05:12 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// This function calculates in bits where we are exactly in the grid
// and assigns a color to the pixel in the image buffer.
static void	my_pixel_put(int x, int y, t_imag *imag, int color)
{
	int	offset;

	offset = (y * imag->line_len) + (x * (imag->bpp / 8));
	*(unsigned int *)(imag->pixels_ptr + offset) = color;
}

// This function can be used to rescale the x and y values in the
// grid to the -2 to +2 range in which the Mandelbrot set can be 
// visualized.
//
// I also use the function in this program to determine the color of the
// pixel. The fewer iterations the value needs to escape towards infinity, 
// the lighter or darker it will be.
double	scale(double val, double new_min, double new_max, double old_max)
{
	double	rescaled;

	rescaled = (new_max - new_min) * val / old_max + new_min;
	return (rescaled);
}

static void	determine_c(t_complex *z, t_complex *c, t_fract *fractal)
{
	if (!ft_strcmp(fractal->name, "mandelbrot"))
	{
		c->real = z->real;
		c->i = z->i;
	}
	else if (!ft_strcmp(fractal->name, "julia"))
	{
		c->real = fractal->julia_x;
		c->i = fractal->julia_y;
	}
}

// Here is where the algorithm is implemented: this function checks for 
// every pixel in the grid whether it is part of the Mandelbrot set by 
// applying the formula z = z^2 + c again and again, using (0,0) as the
// starting value of z. (This is different for the Julia set).
//
// Either the consecutive results stay within a limited range (=> they
// are part of the Mandelbrot set) or they 'escape' towards infinity 
// (=> they are outside the set, which in visual terms means that they
// won't be part of the resulting fractal object, and stay uncolored).
//
// The more iterations one does, the more detailed the fractal
//
// For Julia: we use the determine_c function to set the values of c
// 
void	calculate_f(int x, int y, t_fract *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real = scale(x, fractal->min_r, fractal->max_r, 800) - fractal->shift_x;
	z.i = scale(y, fractal->min_r, fractal->max_r, 800) - fractal->shift_y;
	determine_c(&z, &c, fractal);
	i = 0;
	while (i < fractal->max_iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.i * z.i) > fractal->escape_value)
		{
			color = scale(i, BLACK, WHITE, fractal->max_iterations);
			my_pixel_put(x, y, &fractal->imag, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->imag, WHITE);
}

// this function just loops through every pixel of the grid in order
// to check if it's part of the Mandelbrot set and to determine its color
void	render_fract(t_fract *fractal)
{
	int	x;
	int	y;

	mlx_clear_window(fractal->mlx_con, fractal->mlx_win);
	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			calculate_f(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_con, fractal->mlx_win, 
		fractal->imag.img_ptr, 0, 0);
}
