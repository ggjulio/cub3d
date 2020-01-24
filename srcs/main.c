/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:14:37 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/24 22:05:34 by juligonz         ###   ########.fr       */
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
//	while (y_end < RES_Y)
//		put_pixel(&(game->app), create_vector(x, y_end++), floor);		
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
//	printf("line_height:%d\nstart: %d\nend: %d\ndir.x: %f\ndir.y: %f\n", line_height, r->wall_start, r->wall_end, g->cam.dir.x, g->cam.dir.y);
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

void move(t_game *g, int worldMap[24][24])
{
	t_camera *cam = &(g->cam);
	double speed = 0.4;
	double lat_speed = 0.2;
	double rot_speed = 0.1;

//	t_camera old_cam = g->cam;

	(void)cam;
	printf("pos.x: %f | pos.y: %f\ndir.x: %f | dir.y: %f", g->cam.pos.x, g->cam.pos.y, g->cam.dir.x, g->cam.dir.y);
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
    if (g->key_a)
    {
		if(!worldMap[(int)(g->cam.pos.x - g->cam.plane.x * lat_speed)][(int)g->cam.pos.y])
			g->cam.pos.x -= g->cam.plane.x * lat_speed;
		if(!worldMap[(int)g->cam.pos.x][(int)(g->cam.pos.y - g->cam.plane.y * lat_speed)])
			g->cam.pos.y -= g->cam.plane.y * lat_speed;
    }
    if (g->key_d)
    {
		if (!worldMap[(int)(g->cam.pos.x + g->cam.plane.x * lat_speed)][(int)g->cam.pos.y])
			g->cam.pos.x += g->cam.plane.x * lat_speed;
		if (!worldMap[(int)g->cam.pos.x][(int)(g->cam.pos.y + g->cam.plane.y * lat_speed)])
			g->cam.pos.y += g->cam.plane.y * lat_speed;
    }
    if (g->key_right || g->key_left)
    {
		double old  = g->cam.dir.x;
		rot_speed = g->key_right ? -rot_speed : rot_speed;

		g->cam.dir.x = g->cam.dir.x * cos(rot_speed) - g->cam.dir.y * sin(rot_speed);
		g->cam.dir.y = old * sin(rot_speed) + g->cam.dir.y * cos(rot_speed);
		old = g->cam.plane.x;
		g->cam.plane.x = g->cam.plane.x * cos(rot_speed) - g->cam.plane.y * sin(rot_speed);
		g->cam.plane.y = old * sin(rot_speed) + g->cam.plane.y * cos(rot_speed);
	}
}

int do_job(t_game *g)
{

	int worldMap[24][24]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,0,1,0,0,0,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1},
	{1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

	move(g, worldMap);
	raycasting(g, worldMap);
	render_application(&(g->app));
//	mlx_string_put(app.mlx_ptr, app.win_ptr, 0, 0, create_color(255, 255, 255, 0).c, "Shit");
	return (0);
}

int	main(int ac, char **av)
{
	t_game			g;

	(void)av;
	if (ac == 2)
	{
//		load_cub(av[1], &g);
		printf("check game struct here");
//		exit(0);
	}
	else
	{
		printf(".cub file missing\n");
		exit(0);
	}
	
	g.app = create_application(RES_X, RES_Y,"Shit");
	g.map = malloc(sizeof(uint8_t) * 24 * 24);

//	g.cam = create_camera((t_fvector){0.0,0.0},(t_fvector){0.0,0.0},(t_fvector){0.0,0.0});
	g.cam.pos.x = 17; g.cam.pos.y = 17; // start pos 
	g.cam.dir.x = -1.0; g.cam.dir.y = 0.0; //initial direction vector
	g.cam.plane.x = 0; g.cam.plane.y = 0.57; //the "screen"

	mlx_do_key_autorepeatoff(g.app.mlx_ptr);
	mlx_hook(g.app.win_ptr, KEYPRESS, KEYPRESSMASK, is_key_press, &g);
	mlx_hook(g.app.win_ptr, KEYRELEASE, KEYRELEASEMASK, is_key_release, &g);
	mlx_hook(g.app.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_program, &g);
//	mlx_mouse_hide();
	mlx_loop_hook(g.app.mlx_ptr, do_job, &g);
	mlx_loop(g.app.mlx_ptr);
	return (0);
}

