/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:22:57 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/10 14:37:03 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_movement(void)
{
	static int	old_x;
	int			x;
	int			y;

	mlx_mouse_get_pos(g_app.win_ptr, &x, &y);
	if (old_x == 0)
		old_x = g_app.res.x / 2;
	if (old_x < x && (g_game.is_mouse_move = 1))
	{
		g_game.key_right = 1;
		g_game.key_left = 0;
	}
	else if (old_x > x && (g_game.is_mouse_move = 1))
	{
		g_game.key_left = 1;
		g_game.key_right = 0;
	}
	else if (old_x == x && g_game.is_mouse_move)
	{
		g_game.key_right = 0;
		g_game.key_left = 0;
		old_x = x;
	}
	mlx_mouse_move(g_app.win_ptr, g_app.res.x / 2, 0);
}
