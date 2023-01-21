/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:05:10 by cjudie            #+#    #+#             */
/*   Updated: 2022/06/17 14:48:08 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_data *data)
{
	data->y_y = 0;
	while (data->y_y < HIGHT)
	{
		data->x_x = 0;
		while (data->x_x < WIDTH)
		{
			data->iter = 0;
			map(data);
			iter_loop(data);
			if (data->iter == data->max)
				colors(data, 0);
			else
				colors(data, 1);
			data->x_x++;
		}
		data->y_y++;
	}
	data->stop = 1;
	mlx_hooks(data);
}

void	julia(t_data *data)
{
	data->y_y = 0;
	while (data->y_y < WIDTH)
	{
		data->x_x = 0;
		while (data->x_x < HIGHT)
		{
			data->iter = 0;
			init_x_y(data);
			iter_loop_julia(data);
			if (data->iter == data->max)
				colors(data, 0);
			else
				colors(data, 1);
			data->x_x++;
		}
		data->y_y++;
	}
	mlx_hooks(data);
}

void	init_x_y(t_data *data)
{
	data->xn = ((data->x_x / (double)WIDTH) * (data->x_max - data->x_min))
		+ data->x_min;
	data->yn = ((data->y_y / (double)HIGHT) * (data->y_max - data->y_min))
		+ data->y_min;
}

void	mlx_hooks(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	mlx_hook(data->win, 17, 0L, ft_close, data);
	mlx_hook(data->win, 4, 1, mouse_press, data);
	mlx_hook(data->win, 2, 1, key_push, data);
	mlx_loop(data->mlx);
}
