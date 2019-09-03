/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <tradeshells@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:30:38 by iiskakov          #+#    #+#             */
/*   Updated: 2019/07/29 08:30:39 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scene_reset(t_scene *v)
{
	v->width = W;
	v->height = H;
	v->unit = H / 3;
	v->max.r = 2.0;
	v->zoom = 1.4;
	v->min.r = -2.0;
	v->min.i = -2.0;
	v->zoom_factor = 3;
	v->max.i = v->min.i + (v->max.r - v->min.i) * v->height / v->width;
	v->depth = 90;
	v->re_factor = (v->max.r - v->min.r) / (v->width - 1);
	v->im_factor = (v->max.i - v->min.i) / (v->height - 1);
	v->color_r = 230;
	v->color_g = 230;
	v->color_b = 230;
}

int		scene_parse_fractal_type(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(str, "cubic") == 0)
		return (2);
	else if (ft_strcmp(str, "julia") == 0)
		return (3);
	else if (ft_strcmp(str, "sierpinski") == 0)
		return (4);
	else if (ft_strcmp(str, "poincare") == 0)
		return (5);
	else
		return (0);
}

t_scene	*scene_init(int type)
{
	t_scene		*v;

	v = (t_scene *)malloc(sizeof(t_scene));
	scene_reset(v);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, W, H, "Fract\'ol");
	v->img = mlx_new_image(v->mlx, W, H);
	v->addr = mlx_get_data_addr(v->img, &v->bpp, &v->sl, &v->end);
	v->type = type;
	return (v);
}

void	scene_render(t_scene *v)
{
	mlx_clear_window(v->mlx, v->win);
}

int		scene_close(t_scene *v)
{
	free(v);
	exit(0);
}
