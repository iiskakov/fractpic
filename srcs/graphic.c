/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <tradeshells@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:36:01 by iiskakov          #+#    #+#             */
/*   Updated: 2019/07/29 08:36:02 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	graphic_image_put_pixel(int y, int x, int color, t_scene *res)
{
	if (y >= H || x >= W || y <= 0 || x <= 0)
		return ;
	res->addr[y * res->sl + x * 4] = color & 0x0000ff;
	res->addr[y * res->sl + x * 4 + 1] = (color >> 8) & 0xff;
	res->addr[y * res->sl + x * 4 + 2] = (color >> 16);
}

long	graphic_get_color(double continuous_index, t_scene *v)
{
	t_color_u		c;

	c.c[0] = (unsigned char)(sin(0.16 * continuous_index + 1)
		* v->color_r + 25);
	c.c[1] = (unsigned char)(sin(0.13 * continuous_index + 4)
		* v->color_g + 25);
	c.c[2] = (unsigned char)(sin(0.1 * continuous_index + 6)
		* v->color_b + 25);
	return (((c.c[0] & 0xff) << 16) + ((c.c[1] & 0xff) << 8) +
	(c.c[2] & 0xff));
}

void	graphic_draw(t_scene *v)
{
	double			iteratons;
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < v->height)
	{
		x = 0;
		while (x < v->width)
		{
			iteratons = calculate_fractal(x, y, v);
			graphic_image_put_pixel(y, x, graphic_get_color(iteratons, v), v);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	put_legend(v);
}

double	calculate_fractal(int x, int y, t_scene *v)
{
	if (v->type == 1)
		return (calculate_mandelbrot(x, y, v));
	else if (v->type == 2)
		return (calculate_cubic(x, y, v));
	else if (v->type == 3)
		return (calculate_julia(x, y, v));
	else if (v->type == 4)
		return (calculate_sierpinski(x, y, v));
	else if (v->type == 5)
		return (calculate_poincare(x, y, v));
	return (0);
}

double	calculate_interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}
