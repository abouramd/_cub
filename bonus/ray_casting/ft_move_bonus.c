/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:06:29 by zasabri           #+#    #+#             */
/*   Updated: 2023/08/11 10:06:30 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray_casting_bonus.h"

bool	ft_check_hit(t_global *data, int y, int x)
{
	if (data->map[y][x] == '1')
		return (true);
	if (data->y_d == y && data->x_d == x)
		return (false);
	if (data->map[y][x] == 'D')
		return (true);
	return (false);
}

int	ft_check_sign(double num)
{
	if (num == 0)
		return (0);
	if (num > 0)
		return (1);
	return (-1);
}

void	add_or_sub(double *x, double *y, double co, double si)
{
	(*x) += ft_check_sign(co) * 6;
	(*y) += ft_check_sign(si) * 6;
}

void	move_player(t_global *data, double ang, double *x, double *y)
{
	int		sx;
	int		sy;
	double	co;
	double	si;

	co = cos(ang);
	si = sin(ang) * -1;
	add_or_sub(x, y, co, si);
	sx = -1;
	while (++sx < P_STEP)
	{
		if (ft_check_hit(data, (int)data->player_y / CUB_SIZE, (int)(*x)
			/ CUB_SIZE))
			break ;
		(*x) += co;
	}
	sy = -1;
	while (++sy < P_STEP)
	{
		if (ft_check_hit(data, (int)(*y) / CUB_SIZE, (int)(data->player_x)
				/ CUB_SIZE))
			break ;
		(*y) += si;
	}
	add_or_sub(x, y, -1 * co, -1 * si);
}

void	ft_move(t_global *data, double ang)
{
	double	x;
	double	y;

	x = data->player_x;
	y = data->player_y;
	move_player(data, ang, &x, &y);
	if (!ft_check_hit(data, (int)y / CUB_SIZE, (int)x / CUB_SIZE))
	{
		data->player_x = x;
		data->player_y = y;
	}
	else if (fabs(data->player_x - x))
		data->player_x = x;
	else if (fabs(data->player_y - y))
		data->player_y = y;
}
