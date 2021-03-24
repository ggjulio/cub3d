/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:44:33 by juligonz          #+#    #+#             */
/*   Updated: 2021/03/24 05:43:37 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	change_mouse_state(void)
{
	g_game.mouse_move_enabled = !g_game.mouse_move_enabled;
	if (g_game.mouse_move_enabled)
	{
		mlx_mouse_hide(g_app.mlx_ptr, g_app.win_ptr);
		mlx_mouse_move(g_app.mlx_ptr, g_app.win_ptr, g_app.res.x / 2, g_app.res.y / 2);
	}
	else
		mlx_mouse_show(g_app.mlx_ptr, g_app.win_ptr);
	g_game.key_left = 0;
	g_game.key_right = 0;
}

static void	key_movement(int key, uint8_t value)
{
	if (key == XK_w)
		g_game.key_w = value;
	else if (key == XK_a)
		g_game.key_a = value;
	else if (key == XK_s)
		g_game.key_s = value;
	else if (key == XK_d)
		g_game.key_d = value;
	else if (key == XK_Up)
		g_game.key_up = value;
	else if (key == XK_Down)
		g_game.key_down = value;
	else if (key == XK_Left)
	{
		g_game.key_left = value;
		g_game.is_mouse_move = 0;
	}
	else if (key == XK_Right)
	{
		g_game.key_right = value;
		g_game.is_mouse_move = 0;
	}
	else if (key == XK_Shift_L)
		g_game.is_run = value;
}

static void	key_bonus(int key)
{
	if (key == XK_Tab)
		change_mouse_state();
	else if (key == XK_6)
	{
		play_sound(g_game.snapshot);
		save_image("screenshot.bmp");
	}
	else if (key == XK_q)
	{
		g_game.is_shoot = 1;
		play_sound(g_game.shoot);
	}
	// else if (key == I_KEY)
	// 	mlx_window_toggle_fullscreen(g_app.win_ptr);
	else if (key == XK_7)
		g_game.show_map = !g_game.show_map;
}

int			is_key_press(int key)
{
	key_movement(key, 1);
	key_effects(key);
	key_bonus(key);
	if (key == XK_space)
	{
		g_game.key_space = 1;
		g_game.cam.height = CAMERA_HEIGHT_SQUAT;
	}
	else if (key == XK_Escape)
		exit_game();
	return (0);
}

int			is_key_release(int key)
{
	key_movement(key, 0);
	if (key == XK_space)
	{
		g_game.key_space = 0;
		g_game.cam.height = 0.5;
	}
	return (0);
}
