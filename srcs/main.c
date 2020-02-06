/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:14:37 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/06 16:43:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_movement(t_game *g)
{
	static int	old_x;
	int			x;
	int			y;

	mlx_mouse_get_pos(g->app.win_ptr,  &x, &y);
	printf (">%d %d\n", old_x, x);
	if (old_x == 0)
		old_x = g->app.res.x / 2;
	if (old_x < x && (g->is_mouse_move = 1))
	{
		g->key_right = 1;
		g->key_left = 0;
	}
	else if (old_x > x && (g->is_mouse_move = 1))
	{
		g->key_left = 1;
		g->key_right = 0;
	}
	else if (old_x == x && g->is_mouse_move)
	{
		g->key_right = 0;
		g->key_left = 0;
		old_x = x;
	}
	mlx_mouse_move(g->app.win_ptr, g->app.res.x / 2, 0);
}

int		do_job(t_game *g)
{
	if (g->mouse_move_enabled)
		mouse_movement(g);
	move(g, 0.4, 0.2, 0.1);
	raycasting(g);
	render_application(&(g->app));
	return (0);
}

int		ft_error(char *e)
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
** 	mlx_string_put(app.mlx_ptr, app.win_ptr, 0, 0,\
**				create_color(255, 255, 255, 0).c, "Salut");
*/

int		main(int ac, char **av)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	if (ac != 2)
	{
		ft_printf("Error\n.cub file missing or too many arguments\n");
		exit(0);
	}
	if (load_cub(av[1], &g) == -1)
		exit_game(&g);
	load_textures(&g);

	mlx_do_key_autorepeatoff(g.app.mlx_ptr);
//	mlx_hook(g.app.win_ptr, FOCUSOUT, 0, is_focus_out, &g);
//	mlx_hook(g.app.win_ptr, 6, 0, is_mouse_moved, &g);

	mlx_hook(g.app.win_ptr, KEYPRESS, NOEVENTMASK, is_key_press, &g);
	mlx_hook(g.app.win_ptr, KEYRELEASE, NOEVENTMASK, is_key_release, &g);
	mlx_hook(g.app.win_ptr, DESTROYNOTIFY, NOEVENTMASK, close_program, &g);
	mlx_loop_hook(g.app.mlx_ptr, do_job, &g);
	mlx_loop(g.app.mlx_ptr);
	return (0);
}
