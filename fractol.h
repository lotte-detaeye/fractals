/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:16:23 by lde-taey          #+#    #+#             */
/*   Updated: 2024/05/15 16:06:51 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/X.h>

# define BLACK 		    0x000000
# define WHITE			0xFFFFFF

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 65451
# define KEY_MINUS 65453
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_BTN 1

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;

typedef struct s_imag
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_imag;

typedef struct s_fract
{
	char	*name;
	void	*mlx_con;
	void	*mlx_win;
	t_imag	imag;
	double	escape_value;
	int		max_iterations;
	double	zoom;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
}	t_fract;

void		ft_errorargs(void);
int			ft_strcmp(char *s1, char *s2);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		init_fract(t_fract *fractal);
void		init_hooks(t_fract *fractal);
void		clean_exit(int exit_code, t_fract *fractal);
int			close_event(t_fract *fractal);
double		ft_atodbl(char *str);
void		init_mlx(t_fract *fractal);
double		scale(double val, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex compl1, t_complex compl2);
t_complex	square_complex(t_complex compl);
void		render_fract(t_fract *fractal);
void		handle_pixel(int x, int y, t_fract *fractal);
int			key_event(int keycode, t_fract *fractal);
int			mouse_event(int keycode, int x, int y, t_fract *fractal);

#endif