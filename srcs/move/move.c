/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:02:04 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/22 09:55:20 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(double speed, double lat_speed, double rot_speed)
{
	if (g_game.key_w)
		forward(speed);
	if (g_game.key_s)
		backward(speed);
	if (g_game.key_a)
		left(lat_speed);
	if (g_game.key_d)
		right(lat_speed);
	if (g_game.key_right)
		rotate(rot_speed);
	if (g_game.key_left)
		rotate(-rot_speed);
	if (g_game.key_up)
		look_up();
	if (g_game.key_down)
		look_down();
}
