/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:17:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/26 13:17:50 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define RES_X 1000
#define RES_Y 800

void draw_vertical_line(int x, int y_start, int y_end, t_color color, t_game *game)
{
	t_color ceil = create_color(75,155,105, 0);
	t_color floor = create_color(55,55,55, 0);

	while (y_start < y_end)
		put_pixel(&(game->app), create_vector(x, y_start++), color);
	while (y_end < RES_Y)
	{
		put_pixel(&(game->app), create_vector(x, y_end), floor);
		put_pixel(&(game->app), create_vector(x, RES_Y - y_end), ceil);
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
		r->non_eucl_dist = (r->map.x - g->cam.pos.x + (1 - r->step.x) / 2) / r->ray_dir.x;
	else
		r->non_eucl_dist = (r->map.y - g->cam.pos.y + (1 - r->step.y) / 2) / r->ray_dir.y;
}

void	calculate_wall_height(t_game *g, t_raycast *r)
{
	int line_height = (int)(RES_Y / r->non_eucl_dist);
	(void)g;

	r->wall_start = -line_height / 2 + RES_Y / 2;
	if (r->wall_start < 0)
		r->wall_start = 0;
	r->wall_end = line_height / 2 + RES_Y / 2;
	if (r->wall_end >= RES_Y)
		r->wall_end = RES_Y - 1;
	printf("line_height:%d   start: %d   end: %d   dir.x: %f   dir.y: %f\n", line_height, r->wall_start, r->wall_end, g->cam.dir.x, g->cam.dir.y);
}

void raycasting(t_game *g, int worldMap[24][24])
{
	int x = -1;
	t_raycast r;
	while (++x < RES_X)
	{
		// calculate ray position and direction
		r.camera_x = 2 * x / (double)RES_Y - 1;
		r.ray_dir = (t_fvector){g->cam.dir.x + g->cam.plane.x * r.camera_x,
								g->cam.dir.y + g->cam.plane.y * r.camera_x};
		r.map = (t_vector){(int)g->cam.pos.x, (int)g->cam.pos.y};
		r.delta_dist = (t_fvector){fabs(1 / r.ray_dir.x), fabs(1 / r.ray_dir.y)};
		prehit_wall(g, &r);
		hit_wall(&r, worldMap);
		fix_fisheye(g, &r);
		calculate_wall_height(g, &r);
		t_color color;
		t_color color2;
		if (worldMap[r.map.x][r.map.y] == 1)
			color = create_color(155, 155, 25, 0);
		color2 = create_color(55, 55, 25, 0);
//		if (r.side == 1) 
//			color.c = color.c / 2;
		draw_vertical_line(x, r.wall_start, r.wall_end, r.side == 1 ? color : color2, g);
	}
}

