/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hit_dda_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:06:22 by zasabri           #+#    #+#             */
/*   Updated: 2023/08/11 10:06:23 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray_casting_bonus.h"

bool	check_door(t_global *data, int x, int y, bool hor)
{
	if (data->map[y][x] == 'D' && (data->x_d != x || data->y_d != y))
	{
		if (hor)
		{
			data->dda->door_h = true;
			data->dda->x_d_h = x;
			data->dda->y_d_h = y;
		}
		else
		{
			data->dda->door_v = true;
			data->dda->x_d_v = x;
			data->dda->y_d_v = y;
		}
		return (true);
	}
	if (data->map[y][x] == '1')
		return (true);
	return (false);
}

bool	ft_check_rang(t_global *data, double x, double y, bool hor)
{
	if (x <= 0 || y <= 0)
		return (false);
	if (x >= data->width * CUB_SIZE)
		return (false);
	if (y >= data->height * CUB_SIZE)
		return (false);
	if (check_door(data, x / CUB_SIZE, y / CUB_SIZE, hor))
		return (false);
	if (!hor && check_door(data, (x / CUB_SIZE) - 1, y / CUB_SIZE, hor))
		return (false);
	if (hor && check_door(data, x / CUB_SIZE, (y / CUB_SIZE) - 1, hor))
		return (false);
	return (true);
}

void	dda_setup(t_dda *dda)
{
	double	ang;

	ang = remainder(dda->ang, 2 * M_PI);
	if (ang < 0)
		ang += 2 * M_PI;
	dda->tan = tan(ang);
	dda->co = cos(ang);
	dda->si = sin(ang);
	dda->dir_y = (dda->si < 0) - (dda->si >= 0);
	dda->dir_x = (dda->co >= 0) - (dda->co < 0);
}

void	hor_dda(t_global *data, t_dda *dda)
{
	data->dda->door_h = false;
	data->dda->x_d_h = -1;
	data->dda->y_d_h = -1;
	dda->y_hit_h = CUB_SIZE * (int)(data->player_y / CUB_SIZE
			+ (dda->dir_y == 1));
	dda->x_hit_h = data->player_x + (data->player_y - dda->y_hit_h) / dda->tan;
	while (ft_check_rang(data, dda->x_hit_h, dda->y_hit_h, true))
	{
		dda->y_hit_h += CUB_SIZE * dda->dir_y;
		dda->x_hit_h = data->player_x + (data->player_y - dda->y_hit_h)
			/ dda->tan;
	}
	dda->dis_h = fabs((dda->y_hit_h - data->player_y) / sin(dda->ang));
}

void	ver_dda(t_global *data, t_dda *dda)
{
	data->dda->door_v = false;
	data->dda->x_d_v = -1;
	data->dda->y_d_v = -1;
	dda->x_hit_v = CUB_SIZE * (int)(data->player_x / CUB_SIZE
			+ (dda->dir_x == 1));
	dda->y_hit_v = data->player_y + (data->player_x - dda->x_hit_v) * dda->tan;
	while (ft_check_rang(data, dda->x_hit_v, dda->y_hit_v, false))
	{
		dda->x_hit_v += CUB_SIZE * dda->dir_x;
		dda->y_hit_v = data->player_y + (data->player_x - dda->x_hit_v)
			* dda->tan;
	}
	dda->dis_v = fabs((dda->x_hit_v - data->player_x) / cos(dda->ang));
}
