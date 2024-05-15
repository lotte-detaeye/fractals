/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:16:03 by lde-taey          #+#    #+#             */
/*   Updated: 2024/05/15 16:36:53 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_actions(void)
{
	ft_putstr("\n********************  Actions  ********************\n\n");
	ft_putstr("Arrow keys\t\tMove view.\n");
	ft_putstr("Scroll wheel\t\tZoom in and out.\n");
	ft_putstr("+/- \t\t\tChange number of iterations\n");
	ft_putstr("ESC or close window:\tQuit program.\n");
	ft_putstr("\n****************************************************\n");
}

void	ft_errorargs(void)
{
	ft_putstr("\n");
	ft_putstr("😭 Error. Please enter\n"); 
	ft_putstr("./fractol mandelbrot\n");
	ft_putstr("or\n");
	ft_putstr("./fractol julia <real_value> <imaginary_value>\n");
	ft_putstr("\tExample values for the julia set: -0.8 0.156\n");
	ft_putstr("\tor: 0.285 0.01\n");
	ft_putstr("\n");
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_fract	fractal;

	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot")) \
		|| (argc == 4 && !ft_strcmp(argv[1], "julia")))
	{
		fractal.name = argv[1];
		print_actions();
		if (!ft_strcmp(argv[1], "julia"))
		{
			fractal.julia_x = ft_atodbl(argv[2]);
			fractal.julia_y = ft_atodbl(argv[3]);
		}
		init_mlx(&fractal);
		init_hooks(&fractal);
		init_fract(&fractal);
		render_fract(&fractal);
		mlx_loop(fractal.mlx_con);
	}
	else
		ft_errorargs();
	return (0);
}
