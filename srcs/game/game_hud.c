/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 11:07:29 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint8_t		gun_frame(void)
{
	static	uint8_t		frame;
	static	clock_t		last_event;
	const	uint32_t	delay = 0.005 * CLOCKS_PER_SEC;

	if (!g_game.is_shoot)
	{
		last_event = g_game.ticks_end;
		return (0);
	}
	if (g_game.ticks_end - last_event >= delay)
	{
		frame++;
		last_event = g_game.ticks_end;
	}
	if (frame > 4)
	{
		frame = 0;
		g_game.is_shoot = 0;
	}
	return (frame);
}

void	draw_hud(void)
{
	put_image_in_image_center(g_app.img, g_game.reticle,
		keep_ratio(g_game.reticle, (t_vector){g_app.res.x / 40, g_app.res.y / 40}),
		(t_vector){0, 0});
	put_image_in_image_center_bottom(g_app.img, g_game.weapon[gun_frame()],
		keep_ratio(g_game.weapon[gun_frame()],
		(t_vector){g_app.res.x / 4, g_app.res.y / 4}), (t_vector){g_app.res.x / 4,0});
}
