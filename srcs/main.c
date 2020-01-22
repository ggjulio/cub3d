/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:14:37 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/22 20:21:15 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define RES_X 1000
#define RES_Y 1000

void draw_vertical_line(int x, int start, int end, t_color color, t_game *game)
{
	int i;

	i = 0;
	t_color ceil = create_color(75,155,105, 0);
	while(i < start)
		put_pixel(&(game->app), create_vector(x, i++), ceil);
	while (start < end)
		put_pixel(&(game->app), create_vector(x, start++), color);
	t_color floor = create_color(55,55,55, 0);
	while (end < RES_Y)
		put_pixel(&(game->app), create_vector(x, end++), floor);		
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

void raycasting(t_game *g, int worldMap[24][24])
{
	int x = -1;
	t_raycast r;
	while (++x < RES_X)
	{
		// calculate ray position and direction
		r.camera_x = 2 * x / (double)RES_Y - 1;
		r.ray_dir = create_fvector(g->cam.dir.x + g->cam.plane.x * r.camera_x,
								   g->cam.dir.y + g->cam.plane.y * r.camera_x);
		// which box of the map we're in
		r.map = create_vector((int)g->cam.pos.x, (int)g->cam.pos.y);
		// length of ray from one x or y-side to next x or y-side
		r.delta_dist = create_fvector(fabs(1 / r.ray_dir.x), fabs(1 / r.ray_dir.y));

		prehit_wall(g, &r);	
		hit_wall(&r, worldMap);			//DDA

		fix_fisheye(g, &r);

		//Calculate height of line to draw on screen
		int line_height = (int)(RES_Y / r.non_eucl_dist);

		//calculate lowest and highest pixel to fill in current stripe

		r.wall_start = -line_height / 2 + RES_Y / 2;
		if (r.wall_start < 0)
			r.wall_start = 0;
		r.wall_end = line_height / 2 + RES_Y / 2;
		if (r.wall_end >= RES_Y)
			r.wall_end = RES_Y - 1;

		t_color color;
		if (worldMap[r.map.x][r.map.y] == 1)
			color = create_color(155, 155, 25, 0);

		if (r.side == 1) 
			color.c = color.c / 2;
		draw_vertical_line(x, r.wall_start, r.wall_end, color, g);
	}
}

void move(t_game *g, int worldMap[24][24])
{
	t_camera *cam = &(g->cam);
	double speed = 0.2;
	double rot_speed = 0.05;

	(void)cam;
	if (g->key_w)
    {
		if (!worldMap[(int)(g->cam.pos.x + g->cam.dir.x * speed)][(int)g->cam.pos.y])
			g->cam.pos.x += g->cam.dir.x * speed;
		if (!worldMap[(int)g->cam.pos.x][(int)(g->cam.pos.y + g->cam.dir.y * speed)])
			g->cam.pos.y += g->cam.dir.y * speed;
    }
    if (g->key_s)
    {
		if(!worldMap[(int)(g->cam.pos.x - g->cam.dir.x * speed)][(int)g->cam.pos.y])
			g->cam.pos.x -= g->cam.dir.x * speed;
		if(!worldMap[(int)g->cam.pos.x][(int)(g->cam.pos.y - g->cam.dir.y * speed)])
			g->cam.pos.y -= g->cam.dir.y * speed;
    }
    if (g->key_right)
    {
		double old_dir_x = g->cam.dir.x;
		g->cam.dir.x = g->cam.dir.x * cos(-rot_speed) - g->cam.dir.y * sin(-rot_speed);
		g->cam.dir.y = old_dir_x * sin(-rot_speed) + g->cam.dir.y * cos(-rot_speed);

		double old_plane_x = g->cam.plane.x;
		g->cam.plane.x = g->cam.plane.x * cos(-rot_speed) - g->cam.plane.y * sin(-rot_speed);
		g->cam.plane.y = old_plane_x * sin(-rot_speed) + g->cam.plane.y * cos(-rot_speed);
    }
/*    if (g->key_left)
    {
		double old_dir_x = g->cam.dir.x;
		g->cam.dir.x = g->cam.dir.x * cos(rot_speed) - g->cam.dir.y * sin(rot_speed);
		g->cam.dir.y = old_dir_x * sin(rot_speed) + g->cam.dir.y * cos(rot_speed);
		double old_plane_x = g->cam.plane.x;
		g->cam.plane.x = planeX * cos(rot_speed) - planeY * sin(rot_speed);
		g->cam.plane.y = oldPlaneX * sin(rot_speed) + planeY * cos(rot_speed);
		}*/
}

int do_job(t_game *g)
{

	int worldMap[24][24]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,1,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

	move(g, worldMap);
	raycasting(g, worldMap);
	render_application(&(g->app));
	return (0);
}

int resize_windows(int key, t_game *g)
{
	(void)key;
	(void)g;
	return (0);
}

int	main(void)
{
	t_game			g;
	t_application	app;

	app = create_application(1000,1000,"Shit");
	g = create_game(app,	create_camera(
						   (t_fvector){0.0,0.0},
						   (t_fvector){0.0,0.0},
						   (t_fvector){0.0,0.0}),
					   malloc(sizeof(uint8_t) * 24 * 24)
		);

	g.cam.pos.x = 18; g.cam.pos.y = 17; // start pos 
	g.cam.dir.x = -1; g.cam.dir.y = -0.4; //initial direction vector
	g.cam.plane.x = 0; g.cam.plane.y = 0.66; //the 2d raycaster version of camera plane

	mlx_do_key_autorepeatoff(app.mlx_ptr);
	mlx_hook(app.win_ptr, KEYPRESS, KEYPRESSMASK, is_key_press, &g);
	mlx_hook(app.win_ptr, KEYRELEASE, KEYRELEASEMASK, is_key_release, &g);
	mlx_hook(app.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_program, &g);
	mlx_hook(app.win_ptr, EXPOSE, NOEVENTMASK, resize_windows, &g);
	mlx_loop_hook(app.mlx_ptr, do_job, &g);
	mlx_loop(app.mlx_ptr);
	return (0);
}

//	mlx_string_put(game->app->mlx_ptr, game->app->win_ptr, 0, 0, create_color(255, 255, 255, 0).c, "Shit");
