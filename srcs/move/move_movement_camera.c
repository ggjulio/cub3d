/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_movement_camera.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:02:04 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/08 14:38:36 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(double rot_speed)
{
	double old;

	old = g_game.cam.dir.x;
	g_game.cam.dir.x =
		g_game.cam.dir.x * cos(rot_speed) - g_game.cam.dir.y * sin(rot_speed);
	g_game.cam.dir.y = old * sin(rot_speed) + g_game.cam.dir.y * cos(rot_speed);
	old = g_game.cam.plane.x;
	g_game.cam.plane.x =
		g_game.cam.plane.x * cos(rot_speed)
		- g_game.cam.plane.y * sin(rot_speed);
	g_game.cam.plane.y =
		old * sin(rot_speed) + g_game.cam.plane.y * cos(rot_speed);
}

void	look_up(void)
{
	if (g_game.y_offset > -g_app.res.y / 3)
		g_game.y_offset -= 15;
}

void	look_down(void)
{
	if (g_game.y_offset < g_app.res.y / 3)
		g_game.y_offset += 15;
}
