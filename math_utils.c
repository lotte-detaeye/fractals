/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:22:34 by lde-taey          #+#    #+#             */
/*   Updated: 2024/05/14 14:45:30 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// formula for the sum of two complex numbers
t_complex	sum_complex(t_complex compl1, t_complex compl2)
{
	t_complex	result;

	result.real = compl1.real + compl2.real;
	result.i = compl1.i + compl2.i;
	return (result);
}

// formula for the square of a complex number:
// z^2
// real part: x^2 - y^2
// imaginary part: 2xy
t_complex	square_complex(t_complex compl)
{
	t_complex	result;

	result.real = (compl.real * compl.real) - (compl.i * compl.i);
	result.i = 2 * compl.i * compl.real;
	return (result);
}
