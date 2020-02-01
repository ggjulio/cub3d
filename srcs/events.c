/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:44:33 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/01 17:48:49 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_key_press(int key, t_game *g)
{
	if (key == W_KEY)
		g->key_w = 1;
	else if (key == A_KEY)
		g->key_a = 1;
	else if (key == S_KEY)
		g->key_s = 1;
	else if (key == D_KEY)
		g->key_d = 1;
	else if (key == LEFT_KEY)
	{
		g->key_left = 1;
		g->is_mouse_move = 0;
	}
	else if (key == RIGHT_KEY)
	{
		g->key_right = 1;
		g->is_mouse_move = 0;
	}
	else if (key == ESC_KEY)
		exit_game(g);
	return (0);
}

int	is_key_release(int key, t_game *g)
{
	if (key == W_KEY)
		g->key_w = 0;
	else if (key == A_KEY)
		g->key_a = 0;
	else if (key == S_KEY)
		g->key_s = 0;
	else if (key == D_KEY)
		g->key_d = 0;
	else if (key == LEFT_KEY)
		g->key_left = 0;
	else if (key == RIGHT_KEY)
		g->key_right = 0;
	return (0);
}

int	is_focus_out(int key, t_game *g)
{
	(void)key;
	printf("focus out:%d\n", key);
	g->key_w = 0;
	g->key_a = 0;
	g->key_s = 0;
	g->key_d = 0;
	g->key_left = 0;
	g->key_right = 0;
	return (0);
}

int	is_mouse_moved(int key, t_game *g)
{
	static int old_x;

	if (old_x == 0)
		old_x = key;
	if (old_x < key && !(g->key_left = 0))
		g->key_right = 1;
	else if (old_x > key && !(g->key_right = 0))
		g->key_left = 1;
	else if (old_x == key)
	{
		g->key_right = 0;
		g->key_left = 0;
		old_x = key;
    }

	(void)g;
	printf("mouse event key:%d\n", key);
	return (0);
}

int	close_program(int key, t_game *g)
{
	(void)key;
	return (exit_game(g));
}
