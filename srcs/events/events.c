/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:44:33 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/17 17:56:00 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_focus_out(void)
{
	t_color color_str;

	color_str = create_color(255,255,255,255);
	clear_application(
		create_color(0,0,0,100));
	render_application();
	mlx_string_put(g_app.mlx_ptr, g_app.win_ptr, 
				   g_app.res.x / 2.3, 
				   g_app.res.y / 2.1,
				   color_str.c, "Resume Game");
    mlx_loop_hook(g_app.mlx_ptr, NULL, NULL);
	return (0);
}

int		is_focus_in(void)
{
    mlx_loop_hook(g_app.mlx_ptr, loop_game, NULL);
	return (0);
}

int		is_mouse_moved(int key)
{
	static int old_x;

	if (old_x == 0)
		old_x = key;
	if (old_x < key && !(g_game.key_left = 0))
		g_game.key_right = 1;
	else if (old_x > key && !(g_game.key_right = 0))
		g_game.key_left = 1;
	else if (old_x == key)
	{
		g_game.key_right = 0;
		g_game.key_left = 0;
		old_x = key;
	}
	return (0);
}

int		close_program(int key)
{
	(void)key;
	return (exit_game());
}
