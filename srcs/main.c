/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:23:09 by juligonz          #+#    #+#             */
/*   Updated: 2021/03/23 12:07:40 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game			g_game;
t_application	g_app;

static void	set_mlx(void)
{
	mlx_do_key_autorepeatoff(g_app.mlx_ptr);
	mlx_do_sync(g_app.mlx_ptr);
	mlx_hook(g_app.win_ptr, KeyPress, KeyPressMask, is_key_press, NULL);
	mlx_hook(g_app.win_ptr, KeyRelease, KeyReleaseMask, is_key_release, NULL);
	// mlx_hook(g_app.win_ptr, DestroyNotify, ButtonPressMask, close_program, NULL);
	mlx_hook(g_app.win_ptr, ClientMessage, ButtonPressMask, close_program, NULL);
	mlx_hook(g_app.win_ptr, FocusIn, FocusChangeMask, is_focus_out, NULL);
	mlx_hook(g_app.win_ptr, FocusIn, FocusChangeMask, is_focus_in, NULL);
	mlx_hook(g_app.win_ptr,
		ConfigureNotify, ResizeRedirectMask, is_configure_notify, NULL);
	mlx_loop_hook(g_app.mlx_ptr, loop_game, NULL);
	// mlx_window_set_min_size(g_app.win_ptr, WIN_MIN_WIDTH, WIN_MIN_HEIGHT);
	// mlx_window_resizable_on(g_app.win_ptr);
}

static void	check_args(int ac, char **av)
{
	if (ac != 2 && ac != 3)
	{
		ft_printf("Error\n.cub file missing or too many arguments\n");
		exit(1);
	}
	if (ac == 3 && ft_strcmp(av[2], "--save"))
	{
		ft_printf("Error\n.cub Second argument incorrect\n");
		exit(1);
	}
}

int			main(int ac, char **av)
{
	g_game = create_game();
	g_app = create_application();
	check_args(ac, av);
	if (load_cub(av[1]) == -1)
		exit_game();
	g_app = init_application(g_app, g_app.res.x, g_app.res.y, "Super Cub");
	load_textures();
	load_sounds();
	if (ac == 3)
	{
		raycasting();
		save_image("screenshot.bmp");
		exit_game();
	}
	set_mlx();
	play_sound(g_game.ambiance);
	mlx_loop(g_app.mlx_ptr);
	return (0);
}
