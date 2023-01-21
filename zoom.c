/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:34:33 by cjudie            #+#    #+#             */
/*   Updated: 2022/06/17 15:18:54 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_press(int button, int x, int y, t_data *data)
{
	if (button == 5)
		zoom(data, (double)x, (double)y, 1.3);
	else if (button == 4)
		zoom(data, (double)x, (double)y, 0.9);
	check_argv(data);
	return (1);
}

void	zoom(t_data *data, double x, double y, double zoom)
{
	double	xx;
	double	yy;

	xx = ((x / WIDTH) * (data->x_max - data->x_min)) + data->x_min;
	yy = ((y / HIGHT) * (data->y_max - data->y_min)) + data->y_min;
	data->x_min = xx + ((data->x_min - xx) * zoom);
	data->x_max = xx + ((data->x_max - xx) * zoom);
	data->y_min = yy + ((data->y_min - yy) * zoom);
	data->y_max = yy + ((data->y_max - yy) * zoom);
	if (data->max <= 120)
		data->max += 2;
}

void	zoom_plus(t_data *data)
{
	if (data->x_min < 0 && data->y_min < 0
		&& data->x_max > 0 && data->y_max > 0)
	{
		data->x_min = data->x_min + 0.040;
		data->y_min = data->y_min + 0.040;
		data->x_max = data->x_max - 0.040;
		data->y_max = data->y_max - 0.040;
	}
}

void	zoom_minus(t_data *data)
{
	data->x_min = data->x_min - 0.040;
	data->y_min = data->y_min - 0.040;
	data->x_max = data->x_max + 0.040;
	data->y_max = data->y_max + 0.040;
}
