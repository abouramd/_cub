#include "../include/ray_casting.h"

#define WALL_PROJ(d) (CUB_SIZE * W_HEIGTH / d) 


void line_draw(t_global *data, t_dda *dda, double x, double y, double i, double j)
{
	double t,n;
	t = dda->co;
	n = dda->si * -1;

	while (((dda->dir_x == 1 && x <= i) || (dda->dir_x == -1 && x >= i)) 
				&& ((dda->dir_y == 1 && y <= j) || (dda->dir_y == -1 && y >= j)) && (x >= 0 && y >= 0 && x < data->width * CUB_SIZE && y < data->hiegth * CUB_SIZE))
	{
		my_mlx_pixel_put(&data->img, x, y, BLUE);
		x += t;
		y += n;
	}
}

void choose_ver_hor(t_dda *dda)
{
	if (dda->dis_v >= dda->dis_h)
	{
		dda->dis = dda->dis_h;
		dda->x_hit = dda->x_hit_h;
		dda->y_hit = dda->y_hit_h;
	}
	else
	{
		dda->dis = dda->dis_v;
		dda->x_hit = dda->x_hit_v;
		dda->y_hit = dda->y_hit_v;
	}
	dda->wall_hiegth = WALL_PROJ(dda->dis);
}

void send_rays(t_global *data)
{
	t_dda dda;
	int count_rays = 0;
	double val = (30 * M_PI / 180);

	dda.ang = data->angle_of_view - val;
	val /= 500;
	while (count_rays++ < 1000)
	{
		dda_setup(&dda);
		ver_dda(data, &dda);
		hor_dda(data, &dda);
		choose_ver_hor(&dda);
		line_draw(data, &dda, data->player_x, data->player_y, dda.x_hit, dda.y_hit);
		dda.ang += val;
	}
}
