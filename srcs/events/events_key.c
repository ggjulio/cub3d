/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:44:33 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 21:36:49 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	change_mouse_state(void)
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

static void	key_movement(int key, uint8_t value)
{
	if (key == W_KEY)
		g_game.key_w = value;
	else if (key == A_KEY)
		g_game.key_a = value;
	else if (key == S_KEY)
		g_game.key_s = value;
	else if (key == D_KEY)
		g_game.key_d = value;
	else if (key == UP_KEY)
		g_game.key_up = value;
	else if (key == DOWN_KEY)
		g_game.key_down = value;
	else if (key == LEFT_KEY)
	{
		g_game.key_left = value;
		g_game.is_mouse_move = 0;
	}
	else if (key == RIGHT_KEY)
	{
		g_game.key_right = value;
		g_game.is_mouse_move = 0;
	}
	else if (key == LSFT_KEY)
		g_game.is_run = value;
}

static void	key_bonus(int key)
{
	if (key == TAB_KEY)
		change_mouse_state();
	else if (key == P_KEY)
	{
		play_sound(g_game.snapshot);
		save_image("screenshot.bmp");
	}
	else if (key == Q_KEY)
	{
		g_game.is_shoot = 1;
		play_sound(g_game.shoot);
	}
	else if (key == I_KEY)
		mlx_window_toggle_fullscreen(g_app.win_ptr);
	else if (key == O_KEY)
		g_game.show_map = !g_game.show_map;
}

int			is_key_press(int key)
{
	key_movement(key, 1);
	key_effects(key);
	key_bonus(key);
	if (key == SP_KEY)
	{
		g_game.key_space = 1;
		g_game.cam.height = CAMERA_HEIGHT_SQUAT;
	}
	else if (key == ESC_KEY)
		exit_game();
	return (0);
}

int			is_key_release(int key)
{
	key_movement(key, 0);
	if (key == SP_KEY)
	{
		g_game.key_space = 0;
		g_game.cam.height = 0.5;
	}
	return (0);
}
