/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <tradeshells@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 08:43:29 by iiskakov          #+#    #+#             */
/*   Updated: 2019/06/30 18:13:37 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	controls_move_camera(int key, t_scene *v)
{
	int	tmp;

	tmp = v->min.i;
	if (key == 13)
	{
		v->min.i -= (v->max.r - tmp) / (W) * 2;
		v->max.i -= (v->max.r - tmp) / (W) * 2;
	}
	else if (key == 1)
	{
		v->min.i += (v->max.r - tmp) / (W) * 2;
		v->max.i += (v->max.r - tmp) / (W) * 2;
	}
	else if (key == 0)
	{
		v->min.r += (v->max.r - tmp) / (W) * 2;
		v->max.r += (v->max.r - tmp) / (W) * 2;
	}
	else if (key == 2)
	{
		v->min.r -= (v->max.r - tmp) / (W) * 2;
		v->max.r -= (v->max.r - tmp) / (W) * 2;
	}
}

int		controls_scroll(int button, int x, int y, t_scene *v)
{
	double interpolation;

	if (button == 4 || button == 5)
	{
		v->mouse_re = (double)x / ((W - 1) /
						(v->max.r - v->min.r)) + v->min.r;
		v->mouse_im = (double)y / ((H - 1) /
						(v->max.i - v->min.i)) + v->min.i;
		v->zoom = (button == 4) ? 1.4 : (1.0 / 1.4);
		v->depth = (button == 4) ? v->depth + 5 : (v->depth - 5);
		if (v->depth <= 1)
			v->depth = 30;
		interpolation = 1.0 / v->zoom;
		v->min.r = calculate_interpolate(v->mouse_re, v->min.r, interpolation);
		v->min.i = calculate_interpolate(v->mouse_im, v->min.i, interpolation);
		v->max.r = calculate_interpolate(v->mouse_re, v->max.r, interpolation);
		v->max.i = calculate_interpolate(v->mouse_im, v->max.i, interpolation);
		v->re_factor = (v->max.r - v->min.r) / (W - 1);
		v->im_factor = (v->max.i - v->min.i) / (H - 1);
		v->zoom_factor += 1;
	}
	graphic_draw(v);
	return (0);
}

int		controls_store_mouse_coords(int x, int y, t_scene *v)
{
	v->mouse_re = (double)x / ((W - 1) / (v->max.r - v->min.r)) + v->min.r;
	v->mouse_im = (double)y / ((H - 1) / (v->max.i - v->min.i)) + v->min.i;
	graphic_draw(v);
	return (0);
}

int		controls_key_press(int key, t_scene *v)
{
	if (key == 53)
		scene_close(v);
	else if (key == 13 || key == 0 || key == 1 || key == 2)
		controls_move_camera(key, v);
	else if (key == 15)
		scene_reset(v);
	else if (key == 3)
		v->depth = v->depth + 100;
	else if (key == 16 || key == 32 || key == 34 || key == 31 ||
		key == 35 || key == 33)
		controls_color_change(key, v);
	else if (key == 5)
		v->depth = v->depth - 100;
	graphic_draw(v);
	return (0);
}

int		controls_color_change(int key, t_scene *v)
{
	if (key == 16 && v->color_r < 255)
		v->color_r += 5;
	else if (key == 32 && v->color_r > 5)
		v->color_r -= 5;
	else if (key == 34 && v->color_g < 255)
		v->color_g += 5;
	else if (key == 31 && v->color_g > 5)
		v->color_g -= 5;
	else if (key == 35 && v->color_b < 255)
		v->color_b += 5;
	else if (key == 33 && v->color_b > 5)
		v->color_b -= 5;
	return (0);
}
