/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:17:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/11 16:04:29 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vertical_line(int x, int y_start, int y_end)
{
	while (y_start < y_end)
		put_pixel(create_vector(x, y_start++), g_game.north.color);
	while (y_end < g_app.res.y)
	{
		put_pixel(create_vector(x, y_end), g_game.floor.color);
		put_pixel(create_vector(x, g_app.res.y - y_end), g_game.ceil.color);
		y_end++;
	}
}

/*
void	draw_texel(t_raycast *r, int x, int y_start,)
{
	//if
	r->wall_x = g_game.cam.pos.y + r->perp_wall_dist * r->ray_dir.y;
	// else if

	r->wall_x -= floor(r->wall_x);
	int tex_x = (int)(r->wall_x *g_app.res.x);
	if ((r->side = 0 && r->ray_dir.x > 0)
		|| (r->side = 1 && r->ray_dir.y < 0))
		tex = g_app.res.y - tex_x - 1;

	int step_y = 1.0 * g_app.res.y / r->line_height;
	double tex_pos = r->wall_x 
}
*/









void	prehit_wall(t_raycast *r)
{
	if (r->ray_dir.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x = (g_game.cam.pos.x - r->map.x) * r->delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		r->side_dist.x = (r->map.x + 1.0 - g_game.cam.pos.x) * r->delta_dist.x;
	}
	if (r->ray_dir.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y = (g_game.cam.pos.y - r->map.y) * r->delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		r->side_dist.y = (r->map.y + 1.0 - g_game.cam.pos.y) * r->delta_dist.y;
	}
}

void	dda(t_raycast *r)
{
	while (1)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta_dist.x;
			r->map.x += r->step.x;
			r->side = 0;
		}
		else
		{
			r->side_dist.y += r->delta_dist.y;
			r->map.y += r->step.y;
			r->side = 1;
		}
		if (map_value(r->map.x, r->map.y) > 0)
			break ;
	}
}

void	fix_fisheye(t_raycast *r)
{
	if (r->side == 0)
		r->perp_wall_dist =
			(r->map.x - g_game.cam.pos.x + (1 - r->step.x) / 2) / r->ray_dir.x;
	else
		r->perp_wall_dist =
			(r->map.y - g_game.cam.pos.y + (1 - r->step.y) / 2) / r->ray_dir.y;
}

void	calculate_wall_height(t_raycast *r)
{
	r->line_height = (int)(g_app.res.y / r->perp_wall_dist);
	r->wall_start = -r->line_height / 2 + g_app.res.y / 2;
	if (r->wall_start < 0)
		r->wall_start = 0;
	r->wall_end = r->line_height / 2 + g_app.res.y / 2;
	if (r->wall_end >= g_app.res.y)
		r->wall_end = g_app.res.y - 1;
}

void	raycasting(void)
{
	int			x;
	t_raycast	r;

	x = -1;
	while (++x < g_app.res.x)
	{
		r.camera_x = 2 * x / (double)(g_app.res.y) - 1;
		r.ray_dir = (t_fvector){
			g_game.cam.dir.x + g_game.cam.plane.x * r.camera_x,
			g_game.cam.dir.y + g_game.cam.plane.y * r.camera_x};
		r.map = (t_vector){(int)g_game.cam.pos.x, (int)g_game.cam.pos.y};
		r.delta_dist =
			(t_fvector){fabs(1 / r.ray_dir.x), fabs(1 / r.ray_dir.y)};
		prehit_wall(&r);
		dda(&r);
		fix_fisheye(&r);
		calculate_wall_height(&r);
		draw_vertical_line(x, r.wall_start, r.wall_end);
	}
}
