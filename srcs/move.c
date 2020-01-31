/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:02:04 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/31 12:10:41 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_game *g, double rot_speed)
{
	double old;

	old = g->cam.dir.x;
	g->cam.dir.x =
		g->cam.dir.x * cos(rot_speed) - g->cam.dir.y * sin(rot_speed);
	g->cam.dir.y = old * sin(rot_speed) + g->cam.dir.y * cos(rot_speed);
	old = g->cam.plane.x;
	g->cam.plane.x =
		g->cam.plane.x * cos(rot_speed) - g->cam.plane.y * sin(rot_speed);
	g->cam.plane.y = old * sin(rot_speed) + g->cam.plane.y * cos(rot_speed);
}

void	forward(t_game *g, double speed)
{
	if (!map_value(g,
	(int)(g->cam.pos.x + g->cam.dir.x * speed), (int)g->cam.pos.y))
		g->cam.pos.x += g->cam.dir.x * speed;
	if (!map_value(g,
	(int)g->cam.pos.x, (int)(g->cam.pos.y + g->cam.dir.y * speed)))
		g->cam.pos.y += g->cam.dir.y * speed;
}

void	backward(t_game *g, double speed)
{
	if (!map_value(g,
	(int)(g->cam.pos.x - g->cam.dir.x * speed), (int)g->cam.pos.y))
		g->cam.pos.x -= g->cam.dir.x * speed;
	if (!map_value(g,
	(int)g->cam.pos.x, (int)(g->cam.pos.y - g->cam.dir.y * speed)))
		g->cam.pos.y -= g->cam.dir.y * speed;
}

void	left(t_game *g, double lat_speed)
{
	if (!map_value(g,
	(int)(g->cam.pos.x - g->cam.plane.x * lat_speed), (int)g->cam.pos.y))
		g->cam.pos.x -= g->cam.plane.x * lat_speed;
	if (!map_value(g,
	(int)g->cam.pos.x, (int)(g->cam.pos.y - g->cam.plane.y * lat_speed)))
		g->cam.pos.y -= g->cam.plane.y * lat_speed;
}

void	move(t_game *g, double speed, double lat_speed, double rot_speed)
{
	if (g->key_w)
		forward(g, speed);
	if (g->key_s)
		backward(g, speed);
	if (g->key_a)
		left(g, lat_speed);
	if (g->key_d)
	{
		if (!map_value(g,
		(int)(g->cam.pos.x + g->cam.plane.x * lat_speed), (int)g->cam.pos.y))
			g->cam.pos.x += g->cam.plane.x * lat_speed;
		if (!map_value(g,
		(int)g->cam.pos.x, (int)(g->cam.pos.y + g->cam.plane.y * lat_speed)))
			g->cam.pos.y += g->cam.plane.y * lat_speed;
	}
	if (g->key_right)
		rotate(g, -rot_speed);
	if (g->key_left)
		rotate(g, rot_speed);
}
