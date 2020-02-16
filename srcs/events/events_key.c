/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:44:33 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/16 15:03:03 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_mouse_state(void)
{
	g_game.mouse_move_enabled = !g_game.mouse_move_enabled;
	if (g_game.mouse_move_enabled)
	{
		mlx_mouse_hide();
		mlx_mouse_move(g_app.win_ptr, g_app.res.x / 2, 0);
	}
	else
		mlx_mouse_show();
	g_game.key_left = 0;
	g_game.key_right = 0;
}

int		is_key_press(int key)
{
	if (key == W_KEY)
		g_game.key_w = 1;
	else if (key == A_KEY)
		g_game.key_a = 1;
	else if (key == S_KEY)
		g_game.key_s = 1;
	else if (key == D_KEY)
		g_game.key_d = 1;
	else if (key == LEFT_KEY)
	{
		g_game.key_left = 1;
		g_game.is_mouse_move = 0;
	}
	else if (key == RIGHT_KEY)
	{
		g_game.key_right = 1;
		g_game.is_mouse_move = 0;
	}
	else if (key == LSFT_KEY)
		g_game.is_run = 1;
	else if (key == TAB_KEY)
		change_mouse_state();
	else if (key == P_KEY)
		save_image("test.bmp");
	else if (key == ESC_KEY)
		exit_game();
	return (0);
}

int		is_key_release(int key)
{
	if (key == W_KEY)
		g_game.key_w = 0;
	else if (key == A_KEY)
		g_game.key_a = 0;
	else if (key == S_KEY)
		g_game.key_s = 0;
	else if (key == D_KEY)
		g_game.key_d = 0;
	else if (key == LEFT_KEY)
		g_game.key_left = 0;
	else if (key == RIGHT_KEY)
		g_game.key_right = 0;
	else if (key == LSFT_KEY)
		g_game.is_run = 0;
	return (0);
}
