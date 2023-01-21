/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:09:57 by cjudie            #+#    #+#             */
/*   Updated: 2022/06/15 19:42:50 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	colors(t_data *data, int color)
{
	if (data->color == 20)
	{
		data->index = (4 * 1000 * data->y_y) + data->x_x * 4;
		data->addr[data->index] = (data->iter * data->color) * color;
	}
	else
	{
		data->index = (4 * 1000 * data->y_y) + data->x_x * 4;
		data->addr[data->index] = (data->iter * data->color + 150 + 179)
			* color;
		data->addr[data->index + 1] = (data->iter * data->color + 42 + 84)
			* color;
		data->addr[data->index + 2] = (data->iter * data->color + 936 + 45)
			* color;
		data->addr[data->index + 3] = 0;
	}
}

void	map(t_data *data)
{
	data->xn = data->x_x / (WIDTH / (data->x_max - data->x_min)) + data->x_min;
	data->yn = data->y_y / (HIGHT / (data->y_max - data->y_min)) + data->y_min;
	data->x_0 = data->xn;
	data->y_0 = data->yn;
}

void	iter_loop_julia(t_data *data)
{
	while ((data->iter < data->max)
		&& (data->xn * data->xn + data->yn * data->yn <= 4))
	{
		data->xn_1 = data->xn * data->xn - data->yn * data->yn;
		data->yn_1 = 2 * data->xn * data->yn;
		data->xn = data->xn_1 + data->x_0 + data->julia_x;
		data->yn = data->yn_1 + data->y_0 + data->julia_y;
		if (data->xn * data->xn + data->yn * data->yn > 4)
			break ;
		data->iter++;
	}
}

void	iter_loop(t_data *data)
{
	while (data->iter < data->max)
	{
		data->xn_1 = data->xn * data->xn - data->yn * data->yn;
		if (ft_strcmp(data->name, "Burningship") == 0)
			data->yn_1 = ft_abs(2 * data->xn * data->yn);
		else
			data->yn_1 = 2 * data->xn * data->yn;
		data->xn = data->xn_1 + data->x_0;
		data->yn = data->yn_1 + data->y_0;
		if (data->xn * data->xn + data->yn * data->yn > 4)
			break ;
		data->iter++;
	}
}
