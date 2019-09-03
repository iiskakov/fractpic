/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <tradeshells@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:23:35 by iiskakov          #+#    #+#             */
/*   Updated: 2019/07/29 08:23:37 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# define W 860
# define H 860
# define D double

typedef union
{
	unsigned int		number;
	unsigned char		c[3];
}						t_color_u;

typedef struct			s_color
{
	unsigned char		b;
	unsigned char		g;
	unsigned char		r;
}						t_color;

typedef struct			s_complex_num
{
	double				i;
	double				r;
}						t_complex_num;

typedef struct			s_scene
{
	unsigned int		width;
	unsigned int		height;
	int					unit;
	void				*mlx;
	void				*win;
	void				*img;
	int					bpp;
	int					sl;
	int					end;
	char				*addr;
	t_complex_num		max;
	t_complex_num		min;
	int					depth;
	double				re_factor;
	double				im_factor;
	t_complex_num		z;
	t_complex_num		zz;
	t_complex_num		c;
	double				mouse_re;
	double				mouse_im;
	double				zoom;
	int					zoom_factor;
	int					type;
	int					color_r;
	int					color_g;
	int					color_b;
}						t_scene;

void					put_legend(t_scene *v);
int						controls_color_change(int key, t_scene *v);
void					controls_key_listener(t_scene *v);
int						controls_key_press(int keycode, t_scene *v);
void					controls_move_camera(int key, t_scene *w);
int						controls_scroll(int button, int x, int y, t_scene *v);
int						controls_store_mouse_coords(int x, int y, t_scene *v);
void					scene_reset(t_scene *fdf);
t_scene					*scene_init(int type);
void					scene_render(t_scene *v);
int						scene_parse_fractal_type(char *str);
int						scene_close(t_scene *v);
long					graphic_get_color(double continuous_index, t_scene *v);
void					graphic_draw(t_scene *v);
double					calculate_cubic(int x, int y, t_scene *v);
double					calculate_fractal(int x, int y, t_scene *v);
double					calculate_sierpinski(int x, int y, t_scene *v);
double					calculate_poincare(int x, int y, t_scene *v);
double					calculate_mandelbrot(int x, int y, t_scene *v);
double					calculate_julia(int x, int y, t_scene *v);
double					calculate_interpolate(double start, double end,
	double interpolation);
t_complex_num			calculate_mouse_xy_to_complex(int mouse_x,
	int mouse_y, t_scene *v);
double					calculate_normalize(int i, t_complex_num z);

#endif
