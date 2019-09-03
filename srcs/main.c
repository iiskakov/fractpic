/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <tradeshells@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:23:12 by iiskakov          #+#    #+#             */
/*   Updated: 2019/07/29 18:23:13 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			controls_key_listener(t_scene *v)
{
	mlx_hook(v->win, 2, 0, controls_key_press, v);
	mlx_hook(v->win, 4, 0, controls_scroll, v);
	if (v->type == 3 || v->type == 4 || v->type == 5)
		mlx_hook(v->win, 6, 0, controls_store_mouse_coords, v);
}

void			put_legend(t_scene *v)
{
	mlx_string_put(v->mlx, v->win, 20, 20, 0xFFFFFF,
		"fractol - iiskakov");
	mlx_string_put(v->mlx, v->win, 20, 60, 0xFFFFFF,
		"Coloring R+-|G+-|B+- \t YU|IO|P[ ");
	mlx_string_put(v->mlx, v->win, 20, 80, 0xFFFFFF,
		"Move - WASD");
	mlx_string_put(v->mlx, v->win, 20, 100, 0xFFFFFF,
		"Zoom +\\- \t scroll ");
	mlx_string_put(v->mlx, v->win, 20, 120, 0xFFFFFF,
		"Details +\\- \t f\\g ");
	mlx_string_put(v->mlx, v->win, 20, 140, 0xFFFFFF,
		"Reset - r ");
	mlx_string_put(v->mlx, v->win, 20, 160, 0xFFFFFF,
		"Quit - \"esc\" ");
}

static	void	init_project(int type)
{
	t_scene	*v;

	if (!(v = scene_init(type)))
	{
		write(2, "Usage: ./fractol [mandelbrot] [cubic] [julia]\n", 46);
		exit(0);
	}
	v->type = type;
	graphic_draw(v);
	controls_key_listener(v);
	mlx_loop(v->mlx);
}

int				main(int argc, char **argv)
{
	int		type;
	pid_t	pd;
	int		i;
	int		status;

	status = 0;
	i = 0;
	if (argc < 2)
	{
		write(2, "Usage: ./fractol [mandelbrot] [cubic] [julia]\n", 46);
		return (1);
	}
	while (++i < argc)
	{
		if (!(type = scene_parse_fractal_type(argv[i])))
		{
			write(2, "Usage: ./fractol [mandelbrot] [cubic] [julia]\n", 46);
			return (1);
		}
		if ((pd = fork()) == 0)
			init_project(type);
	}
	while ((pd = wait(&status)) > 0)
		;
	return (0);
}
