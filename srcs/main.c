/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:14:37 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/21 19:59:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define RES_X 1000
#define RES_Y 1000


void draw_vertical_line(int x, int start, int end, t_color color, t_game *game)
{
	while (start < end)
	{
		put_pixel(&(game->app), create_vector(x, start), color);
		start++;
	}
}




void raycasting(t_game *g)
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
	
	t_fvector pos;
	t_fvector dir;
	t_fvector plane;
	pos.x = g->cam.pos.x; pos.y = g->cam.pos.y; // start pos 
	dir.x = g->cam.dir.x; dir.y = g->cam.dir.y; // initial direction vector
	plane.x = g->cam.plane.x; plane.y = g->cam.plane.y; //the 2d raycaster version of camera plane

	int x = -1;
	while (++x < RES_X)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)RES_Y - 1; //x-coordinate in camera space
		t_fvector ray_dir = create_fvector(dir.x + plane.x * cameraX,
										   dir.y + plane.y * cameraX);

		//which box of the map we're in
		t_vector map = create_vector((int)pos.x, (int)pos.y);

		//length of ray from one x or y-side to next x or y-side
		t_fvector delta_dist = create_fvector(fabs(1 / ray_dir.x), fabs(1 / ray_dir.y));

		//what direction to step in x or y-direction (either +1 or -1)
		t_vector step;

		//length of ray from current position to next x or y-side
		t_fvector side_dist;

		//calculate step and initial sideDist
		if(ray_dir.x < 0)
		{
			step.x = -1;
			side_dist.x = (pos.x - map.x) * delta_dist.x;
		}
		else
		{
			step.x = 1;
			side_dist.x = (map.x + 1.0 - pos.x) * delta_dist.x;
		}
		if(ray_dir.y < 0)
		{
			step.y = -1;
			side_dist.y = (pos.y - map.y) * delta_dist.y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (map.y + 1.0 - pos.y) * delta_dist.y;
		}

		int hit = 0;		//was there a wall hit?
		int side;			//was a NS or a EW wall hit?
		//DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += delta_dist.x;
				map.x += step.x;
				side = 0;
			}
			else
			{
				side_dist.y += delta_dist.y;
				map.y += step.y;
				side = 1;
			}	
			if (worldMap[map.x][map.y] > 0) 
				hit = 1;
		}


		double perpWallDist;
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0) 
			perpWallDist = (map.x - pos.x + (1 - step.x) / 2) / ray_dir.x;
		else
			perpWallDist = (map.y - pos.y + (1 - step.y) / 2) / ray_dir.y;

		//Calculate height of line to draw on screen
		int line_height = (int)(RES_Y / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe

		int draw_start = -line_height / 2 + RES_Y / 2;
		if (draw_start < 0)
			draw_start = 0;

		int draw_end = line_height / 2 + RES_Y / 2;
		if (draw_end >= RES_Y)
			draw_end = RES_Y - 1;

		t_color color;
		if (worldMap[map.x][map.y])
			color = create_color(155, 155, 25, 0);

		if (side == 1) 
			color.c = color.c / 2;
		draw_vertical_line(x, draw_start, draw_end, color, g);
	}
}

int do_job(t_game *g)
{

	raycasting(g);

	render_application(&(g->app));
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


	// mlx_hoop pour les touches
	mlx_loop_hook(app.mlx_ptr, do_job, &g);
	mlx_loop(app.mlx_ptr);
	return (0);
}

//	draw_rectangle(&app, create_vector(0, 0), create_vector(100, 100), create_color(255,0,0,0));
//	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img_ptr, 0, 0);
//	mlx_string_put(game->app->mlx_ptr, game->app->win_ptr, 0, 0, create_color(255, 255, 255, 0).c, "Shit");

