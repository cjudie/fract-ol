/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   riffraff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:34:46 by cjudie            #+#    #+#             */
/*   Updated: 2022/06/17 13:13:22 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_close(void)
{
	exit (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

double	tip_help(char *str, double value, char sign, char dec)
{
	double  decimal;
	double  res;
	
	decimal = 1;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			value = (value * 10) + (*str - '0');
			if (dec)
				decimal *= 10;
		}
		else if (*str == '.')
			dec = 1;
		else
			return (1000);
		str++;
	}
	res = sign * (value / decimal);
	return (res);
}

double	tip_atof(char *str)
{
	double  x = 0;


	if (*str == '-' || (*str >= '0' && *str <= '9'))
	{
	    if (*str == '-')
	    {
	        str++;
	        x = tip_help(str, 0, -1, 0);
	    }
	    else
	    	x = tip_help(str, 0, 1, 0);
	}
	else
	    return(100);
	return (x);
}
