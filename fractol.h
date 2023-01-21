/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:33:30 by cjudie            #+#    #+#             */
/*   Updated: 2022/06/17 14:30:45 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define WIDTH 600
# define HIGHT 600

typedef struct s_data
{
	unsigned char	*addr;
	char			*name;
	void			*mlx;
	void			*win;
	void			*image;
	int				line_size;
	int				bpp;
	int				enia;
	int				iter;
	int				index;
	int				zoom;
	int				stop;
	int				max;
	int				color;
	double			julia_x;
	double			julia_y;
	double			x_x;
	double			y_y;
	double			xn;
	double			yn;
	double			x_0;
	double			y_0;
	double			xn_1;
	double			yn_1;
	double			y_min;
	double			y_max;
	double			x_min;
	double			x_max;
}					t_data;

void		mandelbrot(t_data *data);
void		julia(t_data *data);
void		map(t_data *data);
void		colors(t_data *data, int color);
void		initialization(t_data *data, char *str);
void		mlx_hooks(t_data *data);

int			mouse_press(int button, int x, int y, t_data *data);
void		zoom(t_data *data, double x, double y, double zoom);
void		zoom_plus(t_data *data);
void		zoom_minus(t_data *data);
void		init_x_y(t_data *data);
void		iter_loop(t_data *data);
void		iter_loop_julia(t_data *data);

int			ft_close(void);
int			ft_strcmp(char *s1, char *s2);
double		ft_abs(double x);
double		tip_atof(char *str);
double		tip_help(char *str, double value, char sign, char dec);

void		check_argv(t_data *data);
void		check_julia(t_data *data, char *s1, char *s2, int argc);

int			key_push(int keycode, t_data *data);
void		key_push2(int keycode, t_data *data);
void		key_push3(int keycode, t_data *data);

#	endif