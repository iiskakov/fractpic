/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <tradeshells@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:26:38 by iiskakov          #+#    #+#             */
/*   Updated: 2019/07/29 08:26:39 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	calculate_cubic(int x, int y, t_scene *v)
{
	t_complex_num	z;
	t_complex_num	c;
	t_complex_num	tmp;
	int				i;

	z.r = 0;
	z.i = 0;
	i = 0;
	c.i = (double)v->max.i - y * v->im_factor;
	c.r = (double)v->min.r + x * v->re_factor;
	while ((i < v->depth) && z.r * z.r + z.i * z.i <= 4)
	{
		tmp.r = z.r * z.r * z.r - 3 * z.r * z.i * z.i + c.r;
		tmp.i = 3 * z.r * z.r * z.i - z.i * z.i * z.i + c.i;
		z = tmp;
		i++;
	}
	return (i + 1 - (log(2) / (sqrt(z.r * z.r + z.i * z.i))) / log(2));
}

double	calculate_julia(int x, int y, t_scene *v)
{
	t_complex_num	z;
	t_complex_num	tmp;
	int				i;

	z.r = (double)v->min.r + x * v->re_factor;
	z.i = (double)v->max.i - y * v->im_factor;
	i = 1;
	while (i < v->depth && z.r * z.r + z.i * z.i <= 4.0f)
	{
		tmp.r = z.r * z.r - z.i * z.i + v->mouse_re;
		tmp.i = 2 * z.r * z.i + v->mouse_im;
		z = tmp;
		i++;
	}
	return (i + 1 - (log(2) / (sqrt(z.r * z.r + z.i * z.i))) / log(2));
}

double	calculate_poincare(int x, int y, t_scene *v)
{
	t_complex_num	z;
	t_complex_num	tmp;
	int				i;
	float			d;

	z.r = (double)v->min.r + x * v->re_factor;
	z.i = (double)v->max.i - y * v->im_factor;
	i = 1;
	while (i < v->depth && z.r * z.r + z.i * z.i <= 4.0f)
	{
		d = (pow((z.r * z.r - z.i * z.i), 2) - 4 * z.r * z.r * z.i * z.i) * 10;
		tmp.r = z.r * z.r - z.i * z.i + v->mouse_re *
		(z.r * z.r - z.i * z.i) / d
		+ v->mouse_im * 2 * z.r * z.i / d;
		tmp.i = 2 * z.r * z.i - v->mouse_re * 2 * z.r * z.i / d
		+ v->mouse_im * (z.r * z.r - z.i * z.i) / d;
		z = tmp;
		i++;
	}
	return (i + 1 - (log(2) / (sqrt(z.r * z.r + z.i * z.i))) / log(2));
}

double	calculate_sierpinski(int x, int y, t_scene *v)
{
	t_complex_num	z;
	t_complex_num	tmp;
	int				i;
	float			d;

	z.r = (double)v->min.r + x * v->re_factor;
	z.i = (double)v->max.i - y * v->im_factor;
	i = 1;
	while (i < v->depth && z.r * z.r + z.i * z.i <= 4.0f)
	{
		d = (z.r * z.r + z.i * z.i);
		tmp.r = z.r * z.r - z.i * z.i + v->mouse_re * z.r / d
		+ v->mouse_im * z.i / d;
		tmp.i = 2 * z.r * z.i - v->mouse_re * z.i / d
		+ v->mouse_im * z.r / d;
		z = tmp;
		i++;
	}
	return (i + 1 - (log(2) / (sqrt(z.r * z.r + z.i * z.i))) / log(2));
}

double	calculate_mandelbrot(int x, int y, t_scene *v)
{
	t_complex_num	z;
	t_complex_num	c;
	double			zrsqr;
	double			zisqr;
	int				i;

	z.r = 0;
	z.i = 0;
	i = 0;
	zrsqr = 0.0f;
	zisqr = 0.0f;
	c.i = (double)v->max.i - y * v->im_factor;
	c.r = (double)v->min.r + x * v->re_factor;
	while ((i < v->depth) && (zisqr + zrsqr < 4.0f))
	{
		z.i = z.r * z.i;
		z.i += z.i + c.i;
		z.r = zrsqr - zisqr + c.r;
		zrsqr = z.r * z.r;
		zisqr = z.i * z.i;
		i++;
	}
	return (i + 1 - (log(2) / (sqrt(z.r * z.r + z.i * z.i))) / log(2));
}
