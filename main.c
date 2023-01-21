/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:45:20 by cjudie            #+#    #+#             */
/*   Updated: 2022/06/17 14:58:24 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialization(t_data *data, char *str)
{
	data->x_min = -2;
	data->x_max = 2;
	data->y_min = -2;
	data->y_max = 2;
	data->x_0 = -0.4;
	data->y_0 = 0.6;
	data->zoom = 0;
	data->stop = 0;
	data->max = 40;
	data->color = 20;
	data->name = str;
}

void	check_argv(t_data *data)
{
	if (ft_strcmp(data->name, "Mandelbrot") == 0)
		mandelbrot(data);
	else if (ft_strcmp(data->name, "Burningship") == 0)
		mandelbrot(data);
	else if (ft_strcmp(data->name, "Julia") == 0)
		julia(data);
}

void	check_julia(t_data *data, char *s1, char *s2, int argc)
{
	if (argc != 4 || (tip_atof(s1) < -2 || tip_atof(s1) > 2)
		|| (tip_atof(s2) < -2 || tip_atof(s2) > 2))
	{
		write(1, "Error!\nInvalid parameters!\n", 27);
		write(1, "Example:\t./fractol Julia 0.15 1\n", 32);
		write(1, "^^^Acceptable value from -2 to 2\n", 33);
		exit(0);
	}
	data->julia_x = tip_atof(s1);
	data->julia_y = tip_atof(s2);
}

int	main(int argc, char *argv[])
{
	t_data		data;

	if (argc >= 2)
	{
		if (ft_strcmp(argv[1], "Mandelbrot") == 0 || ft_strcmp(argv[1],
				"Burningship") == 0 || ft_strcmp(argv[1], "Julia") == 0)
		{
			data.mlx = mlx_init();
			data.win = mlx_new_window(data.mlx, WIDTH, HIGHT, "Fractol");
			data.image = mlx_new_image(data.mlx, WIDTH + 400, HIGHT);
			data.addr = (unsigned char *)mlx_get_data_addr(data.image,
					&data.bpp, &data.line_size, &data.enia);
		}
		if (ft_strcmp(argv[1], "Julia") == 0)
			check_julia(&data, argv[2], argv[3], argc);
		initialization(&data, argv[1]);
		check_argv(&data);
	}
	else
	{
		write(1, "Error!\n./fractol <name>", 23);
		write(1, "\tMandelbrot\tBurningship\tJulia\n", 30);
	}
	return (0);
}
