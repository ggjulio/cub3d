/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:02:04 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/10 15:04:02 by juligonz         ###   ########.fr       */
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

void	forward(double speed)
{
	if (!map_value(
	(int)(g_game.cam.pos.x + g_game.cam.dir.x * speed), (int)g_game.cam.pos.y))
		g_game.cam.pos.x += g_game.cam.dir.x * speed;
	if (!map_value(
	(int)g_game.cam.pos.x, (int)(g_game.cam.pos.y + g_game.cam.dir.y * speed)))
		g_game.cam.pos.y += g_game.cam.dir.y * speed;
}

void	backward(double speed)
{
	if (!map_value(
	(int)(g_game.cam.pos.x - g_game.cam.dir.x * speed), (int)g_game.cam.pos.y))
		g_game.cam.pos.x -= g_game.cam.dir.x * speed;
	if (!map_value(
	(int)g_game.cam.pos.x, (int)(g_game.cam.pos.y - g_game.cam.dir.y * speed)))
		g_game.cam.pos.y -= g_game.cam.dir.y * speed;
}

void	left(double lat_speed)
{
	if (!map_value(
	(int)(g_game.cam.pos.x - g_game.cam.plane.x * lat_speed),
	(int)g_game.cam.pos.y))
		g_game.cam.pos.x -= g_game.cam.plane.x * lat_speed;
	if (!map_value(
	(int)g_game.cam.pos.x,
	(int)(g_game.cam.pos.y - g_game.cam.plane.y * lat_speed)))
		g_game.cam.pos.y -= g_game.cam.plane.y * lat_speed;
}

void	right(double lat_speed)
{
	if (!map_value(
	(int)(g_game.cam.pos.x + g_game.cam.plane.x * lat_speed),
	(int)g_game.cam.pos.y))
		g_game.cam.pos.x += g_game.cam.plane.x * lat_speed;
	if (!map_value(
	(int)g_game.cam.pos.x,
	(int)(g_game.cam.pos.y + g_game.cam.plane.y * lat_speed)))
		g_game.cam.pos.y += g_game.cam.plane.y * lat_speed;
}