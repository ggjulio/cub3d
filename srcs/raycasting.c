/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:17:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/26 20:16:38 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void draw_vertical_line(int x, int y_start, int y_end,  t_game *g)
{
	while (y_start < y_end)
	{
		put_pixel(&(g->app), create_vector(x, y_start++), g->north.color);
	
	}
	while (y_end < g->app.resolution.y)
	{
		put_pixel(&(g->app), create_vector(x, y_end), g->floor.color);
		put_pixel(&(g->app), create_vector(x, g->app.resolution.y - y_end), g->ceil.color);
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
void	hit_wall(t_raycast *r, int worldMap[24][24])
{
	while (1)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
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
		if (worldMap[r->map.x][r->map.y] > 0) 
			break;
	}
}

//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
void	fix_fisheye(t_game *g, t_raycast *r)
{
	if (r->side == 0) 
		r->perpendicular_dist = (r->map.x - g->cam.pos.x + (1 - r->step.x) / 2) / r->ray_dir.x;
	else
		r->perpendicular_dist = (r->map.y - g->cam.pos.y + (1 - r->step.y) / 2) / r->ray_dir.y;
}

void	calculate_wall_height(t_game *g, t_raycast *r)
{
	int line_height = (int)(g->app.resolution.y / r->perpendicular_dist);

	r->wall_start = -line_height / 2 + g->app.resolution.y / 2;
	if (r->wall_start < 0)
		r->wall_start = 0;
	r->wall_end = line_height / 2 + g->app.resolution.y / 2;
	if (r->wall_end >= g->app.resolution.y)
		r->wall_end = g->app.resolution.y - 1;
}

void raycasting(t_game *g, int worldMap[24][24])
{
	int x = -1;
	t_raycast r;

	while (++x < g->app.resolution.x)
	{
		// calculate ray position and direction
		r.camera_x = 2 * x / (double)(g->app.resolution.y) - 1;
		r.ray_dir = (t_fvector){g->cam.dir.x + g->cam.plane.x * r.camera_x,
								g->cam.dir.y + g->cam.plane.y * r.camera_x};
		r.map = (t_vector){(int)g->cam.pos.x, (int)g->cam.pos.y};
		r.delta_dist = (t_fvector){fabs(1 / r.ray_dir.x), fabs(1 / r.ray_dir.y)};
		prehit_wall(g, &r);
		hit_wall(&r, worldMap);
		fix_fisheye(g, &r);
		calculate_wall_height(g, &r);

		//calculate value of wallX
/*		double wallX; //where exactly the wall was hit
		if (side == 0) 
			r.wall_x = g->cam.pos.y + r.perpendicular_dist * r.ray_dir.y;
		else
			r.wall_x = g->cam.pos.x + r.perpendicular_dist * r.ray_dir.x;
		r.wall_x -= floor(r.wall_x);

		//x coordinate on the texture
		int texX = (int)(wallX * (double(g->);
		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0) 
		texX = texWidth - texX - 1;
*/
		draw_vertical_line(x, r.wall_start, r.wall_end, g);
	}
}

