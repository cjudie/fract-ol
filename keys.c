/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:34:12 by cjudie            #+#    #+#             */
/*   Updated: 2022/06/15 20:06:52 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_push(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 69 && data->stop == 1)
		zoom_plus(data);
	else if (keycode == 78 && data->stop == 1)
		zoom_minus(data);
	else
		key_push2(keycode, data);
	check_argv(data);
	return (1);
}

void	key_push2(int keycode, t_data *data)
{
	if (keycode == 123)
	{
		data->x_min = data->x_min - 0.037;
		data->x_max = data->x_max - 0.037;
	}	
	else if (keycode == 124)
	{
		data->x_min = data->x_min + 0.037;
		data->x_max = data->x_max + 0.037;
	}
	else if (keycode == 125)
	{
		data->y_min = data->y_min + 0.037;
		data->y_max = data->y_max + 0.037;
	}
	else if (keycode == 126)
	{
		data->y_min = data->y_min - 0.037;
		data->y_max = data->y_max - 0.037;
	}
	else
		key_push3(keycode, data);
	check_argv(data);
}

void	key_push3(int keycode, t_data *data)
{
	if (keycode == 82)
		data->color = rand();
	check_argv(data);
}
