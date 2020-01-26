/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:14:37 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/26 15:44:09 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define RES_X 1000
#define RES_Y 800

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
		char *str = "253,1,255";
		printf(">>>>>>%d|\n", valid_color_fmt(str));
		str = "253,,2553";
		printf(">>>>>>%d|\n", valid_color_fmt(str));
		str = "253,3,";
		printf(">>>>>>%d|\n", valid_color_fmt(str));
		str = "2,3,";
		printf(">>>>>>%d|\n", valid_color_fmt(str));
		str = "2,3,3";
		printf(">>>>>>%d|\n", valid_color_fmt(str));
		str = ",,";
		printf(">>>>>>%d|\n", valid_color_fmt(str));
		str = "2,3,256";
		printf(">>>>>>%d|\n", valid_color_fmt(str));
		str = "2,256,255";
		printf(">>>>>>%d|\n", valid_color_fmt(str));



		printf("check game struct here");
		exit(0);
	}
	else
	{
		printf(".cub file missing\n");
		exit(0);
	}
	
	g.app = create_application(RES_X, RES_Y,"Shit");
	g.map = malloc(sizeof(uint8_t) * 24 * 24);

	g.cam.pos.x = 17; g.cam.pos.y = 17; // start pos 
	g.cam.dir.x = -1.0; g.cam.dir.y = 0.0; //initial direction vector
	g.cam.plane.x = 0; g.cam.plane.y = 0.66; //the "screen"

	mlx_do_key_autorepeatoff(g.app.mlx_ptr);
	mlx_hook(g.app.win_ptr, KEYPRESS, KEYPRESSMASK, is_key_press, &g);
	mlx_hook(g.app.win_ptr, KEYRELEASE, KEYRELEASEMASK, is_key_release, &g);
	mlx_hook(g.app.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_program, &g);
//	mlx_mouse_hide();
	mlx_loop_hook(g.app.mlx_ptr, do_job, &g);
	mlx_loop(g.app.mlx_ptr);
	return (0);
}

