/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:02:04 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 22:11:38 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Don't judge me.
*/

static void	check_is_monster(double x, double y)
{
	if (2 == map_value(x, y))
	{
		g_game.life--;
		ft_printf("%d\n", g_game.life);
	}
	if (g_game.life < 1)
		ft_printf("dead\n");
}

void		forward(double speed)
{
	check_is_monster(
(int)(g_game.cam.pos.x + g_game.cam.dir.x * speed), (int)g_game.cam.pos.y);
	check_is_monster(
(int)g_game.cam.pos.x, (int)(g_game.cam.pos.y + g_game.cam.dir.y * speed));
	if (!map_value(
	(int)(g_game.cam.pos.x + g_game.cam.dir.x * speed), (int)g_game.cam.pos.y))
		g_game.cam.pos.x += g_game.cam.dir.x * speed;
	if (!map_value(
	(int)g_game.cam.pos.x, (int)(g_game.cam.pos.y + g_game.cam.dir.y * speed)))
		g_game.cam.pos.y += g_game.cam.dir.y * speed;
}

void		backward(double speed)
{
	check_is_monster(
(int)(g_game.cam.pos.x - g_game.cam.dir.x * speed), (int)g_game.cam.pos.y);
	check_is_monster(
(int)g_game.cam.pos.x, (int)(g_game.cam.pos.y - g_game.cam.dir.y * speed));
	if (!map_value(
	(int)(g_game.cam.pos.x - g_game.cam.dir.x * speed), (int)g_game.cam.pos.y))
		g_game.cam.pos.x -= g_game.cam.dir.x * speed;
	if (!map_value(
	(int)g_game.cam.pos.x, (int)(g_game.cam.pos.y - g_game.cam.dir.y * speed)))
		g_game.cam.pos.y -= g_game.cam.dir.y * speed;
}

void		left(double lat_speed)
{
	check_is_monster((int)(g_game.cam.pos.x - g_game.cam.plane.x * lat_speed),
(int)g_game.cam.pos.y);
	check_is_monster((int)g_game.cam.pos.x,
(int)(g_game.cam.pos.y - g_game.cam.plane.y * lat_speed));
	if (!map_value(
	(int)(g_game.cam.pos.x - g_game.cam.plane.x * lat_speed),
	(int)g_game.cam.pos.y))
		g_game.cam.pos.x -= g_game.cam.plane.x * lat_speed;
	if (!map_value(
	(int)g_game.cam.pos.x,
	(int)(g_game.cam.pos.y - g_game.cam.plane.y * lat_speed)))
		g_game.cam.pos.y -= g_game.cam.plane.y * lat_speed;
}

void		right(double lat_speed)
{
	check_is_monster((int)(g_game.cam.pos.x + g_game.cam.plane.x * lat_speed),
			(int)g_game.cam.pos.y);
	check_is_monster((int)g_game.cam.pos.x,
			(int)(g_game.cam.pos.y + g_game.cam.plane.y * lat_speed));
	if (!map_value(
	(int)(g_game.cam.pos.x + g_game.cam.plane.x * lat_speed),
	(int)g_game.cam.pos.y))
		g_game.cam.pos.x += g_game.cam.plane.x * lat_speed;
	if (!map_value(
	(int)g_game.cam.pos.x,
	(int)(g_game.cam.pos.y + g_game.cam.plane.y * lat_speed)))
		g_game.cam.pos.y += g_game.cam.plane.y * lat_speed;
}
