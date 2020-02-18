/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:23:09 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/18 14:57:30 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game			g_game;
t_application	g_app;

int		main(int ac, char **av)
{
	g_game = create_game();
	g_app = create_application();
	if (ac != 2 && ac != 3)
	{
		ft_printf("Error\n.cub file missing or too many arguments\n");
		exit(0);
	}
	if (ac == 3 && ft_strcmp(av[2], "--save"))
	{
		ft_printf("Error\n.cub Second argument incorrect\n");
		exit(0);
	}
	if (load_cub(av[1]) == -1)
		exit_game();
	g_app = init_application(g_app, g_app.res.x, g_app.res.y, "Super Cub");
	load_textures();
	if (ac == 3)
	{
		raycasting();
		save_image("ok.bmp");
	}
	mlx_do_key_autorepeatoff(g_app.mlx_ptr);
	mlx_hook(g_app.win_ptr, KEYPRESS, NOEVENTMASK, is_key_press, NULL);
	mlx_hook(g_app.win_ptr, FOCUSOUT, NOEVENTMASK, is_focus_out, NULL);
	mlx_hook(g_app.win_ptr, FOCUSIN, NOEVENTMASK, is_focus_in, NULL);
	mlx_hook(g_app.win_ptr, KEYRELEASE, NOEVENTMASK, is_key_release, NULL);
	mlx_hook(g_app.win_ptr, DESTROYNOTIFY, NOEVENTMASK, close_program, NULL);
	mlx_hook(g_app.win_ptr, CONFIGURENOTIFY, NOEVENTMASK, NULL, NULL);
	mlx_loop_hook(g_app.mlx_ptr, loop_game, NULL);
	mlx_loop(g_app.mlx_ptr);
	return (0);
}
