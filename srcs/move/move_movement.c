/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:02:04 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/08 14:38:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
