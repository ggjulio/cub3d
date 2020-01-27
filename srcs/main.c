/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:14:37 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/27 20:07:10 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	if (ac == 2)
	{
		if (load_cub(av[1], &g) == -1)
		{
			ft_printf("syntax error in file !");
			exit_game(&g);
		}
	}
	else
	{
		printf(".cub file missing\n");
		exit(0);
	}
	
	g.app = create_application(g.app.res.x, g.app.res.y,"Shit");

	g.cam.pos.x = 17.0 + 0.5; g.cam.pos.y = 17.0 + 0.5; 
	g.cam.dir.x = -1.0; g.cam.dir.y = 0.0;
	g.cam.plane.x = 0.0; g.cam.plane.y = 0.66;

	double old = g.cam.plane.x;
    g.cam.plane.x = g.cam.plane.x * cos(0) - g.cam.plane.y * sin(0);
    g.cam.plane.y = old * sin(0) + g.cam.plane.y * cos(0);

	mlx_do_key_autorepeatoff(g.app.mlx_ptr);
	mlx_hook(g.app.win_ptr, KEYPRESS, KEYPRESSMASK, is_key_press, &g);
	mlx_hook(g.app.win_ptr, KEYRELEASE, KEYRELEASEMASK, is_key_release, &g);
	mlx_hook(g.app.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_program, &g);
//	mlx_mouse_hide();
	mlx_loop_hook(g.app.mlx_ptr, do_job, &g);
	mlx_loop(g.app.mlx_ptr);
	return (0);
}

