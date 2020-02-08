/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:17:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/07 10:56:48 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint8_t	map_value(t_game *g, int x, int y)
{
	return (g->map[y + x * g->map_len_x]);
}
/*
void	put_texel(t_application *app, t_vector coord, t_color color)
{
	
}
*/
void	draw_vertical_line(int x, int y_start, int y_end,  t_game *g)
{
	while (y_start < y_end)
		put_pixel(&(g->app), create_vector(x, y_start++), g->north.color);
	while (y_end < g->app.res.y)
	{
		put_pixel(&(g->app), create_vector(x, y_end), g->floor.color);
		put_pixel(&(g->app), create_vector(x, g->app.res.y - y_end), g->ceil.color);
		y_end++;
	}
}

// calculate step and initial sideDist
void	prehit_wall(t_game *g, t_raycast *r)
{
	if (r->ray_dir.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x = (g->cam.pos.x - r->map.x) * r->delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		r->side_dist.x = (r->map.x + 1.0 - g->cam.pos.x) * r->delta_dist.x;
	}
	if (r->ray_dir.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y = (g->cam.pos.y - r->map.y) * r->delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		r->side_dist.y = (r->map.y + 1.0 - g->cam.pos.y) * r->delta_dist.y;
	}
}

//DDA (Digital Differential Analysis)
void	hit_wall(t_raycast *r, t_game *g)
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
		if (map_value(g, r->map.x, r->map.y) > 0)
			break;
	}
}

void	fix_fisheye(t_game *g, t_raycast *r)
{
	if (r->side == 0) 
		r->perp_wall_dist = (r->map.x - g->cam.pos.x + (1 - r->step.x) / 2) / r->ray_dir.x;
	else
		r->perp_wall_dist = (r->map.y - g->cam.pos.y + (1 - r->step.y) / 2) / r->ray_dir.y;
}

void	calculate_wall_height(t_game *g, t_raycast *r)
{
	r->line_height = (int)(g->app.res.y / r->perp_wall_dist);
	r->wall_start = -r->line_height / 2 + g->app.res.y / 2;
	if (r->wall_start < 0)
		r->wall_start = 0;
	r->wall_end = r->line_height / 2 + g->app.res.y / 2;
	if (r->wall_end >= g->app.res.y)
		r->wall_end = g->app.res.y - 1;
}

void	raycasting(t_game *g)
{
	int x;
	t_raycast r;

	x = -1;
	while (++x < g->app.res.x)
	{
		r.camera_x = 2 * x / (double)(g->app.res.y) - 1;
		r.ray_dir = (t_fvector){g->cam.dir.x + g->cam.plane.x * r.camera_x,
								g->cam.dir.y + g->cam.plane.y * r.camera_x};
		r.map = (t_vector){(int)g->cam.pos.x, (int)g->cam.pos.y};
		r.delta_dist =
			(t_fvector){fabs(1 / r.ray_dir.x), fabs(1 / r.ray_dir.y)};
		prehit_wall(g, &r);
		hit_wall(&r, g);
		fix_fisheye(g, &r);
		calculate_wall_height(g, &r);
		draw_vertical_line(x, r.wall_start, r.wall_end, g);
	}
}
