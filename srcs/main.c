/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:23:09 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/10 14:45:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game			g_game;
t_application	g_app;

int		do_job()
{
	clear_application(create_color(0, 0, 0, 0));
	if (g_game.mouse_move_enabled)
		mouse_movement();
	move(0.4, 0.2, 0.1);
	raycasting();
	render_application();
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

int		main(int ac, char **av)
{
	ft_bzero(&g_game, sizeof(t_game));
	if (ac != 2)
	{
		ft_printf("Error\n.cub file missing or too many arguments\n");
		exit(0);
	}
	if (load_cub(av[1]) == -1)
		exit_game();
	load_textures();
	mlx_do_key_autorepeatoff(g_app.mlx_ptr);
	mlx_hook(g_app.win_ptr, KEYPRESS, NOEVENTMASK, is_key_press, NULL);
	mlx_hook(g_app.win_ptr, KEYRELEASE, NOEVENTMASK, is_key_release, NULL);
	mlx_hook(g_app.win_ptr, DESTROYNOTIFY, NOEVENTMASK, close_program, NULL);
	mlx_loop_hook(g_app.mlx_ptr, do_job, NULL);
	mlx_loop(g_app.mlx_ptr);
	return (0);
}
