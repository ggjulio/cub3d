/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:14:37 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/30 19:54:59 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	do_job(t_game *g)
{
	move(g);
	raycasting(g);
	render_application(&(g->app));
	return (0);
}

int	ft_error(char *e)
{
	static uint first_call = 1;

	if (first_call)
	{
		ft_printf("Error\n");
		first_call = 0;
	}
	ft_printf("%s\n", e);
	return (-1);
}

/*
** mlx_mouse_hide();
** 	mlx_string_put(app.mlx_ptr, app.win_ptr, 0, 0,\
**				create_color(255, 255, 255, 0).c, "Salut");
*/

int	main(int ac, char **av)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	if (ac == 2)
	{
		if (load_cub(av[1], &g) == -1)
		{
			ft_printf("\n\n||||| ????");
			exit_game(&g);
		}
	}
	else
	{
		ft_printf("Error\n.cub file missing\n");
		exit(0);
	}
	g.app = create_application(g.app.res.x, g.app.res.y, "Cub3D");
	mlx_do_key_autorepeatoff(g.app.mlx_ptr);
	mlx_hook(g.app.win_ptr, KEYPRESS, KEYPRESSMASK, is_key_press, &g);
	mlx_hook(g.app.win_ptr, KEYRELEASE, KEYRELEASEMASK, is_key_release, &g);
	mlx_hook(g.app.win_ptr, DESTROYNOTIFY,\
			STRUCTURENOTIFYMASK, close_program, &g);
	mlx_loop_hook(g.app.mlx_ptr, do_job, &g);
	mlx_loop(g.app.mlx_ptr);
	return (0);
}
