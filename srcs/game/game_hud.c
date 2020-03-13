/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/13 01:00:13 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint8_t	gun_frame(void)
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

void			draw_kills(void)
{
	t_vector size_left;
	t_vector size_right;

	if (g_game.nb_kills > 99)
		g_game.nb_kills = 0;
	size_right = keep_ratio(
		g_game.number[g_game.nb_kills % 10], (t_vector){-1, g_app.res.y / 7});
	size_left = keep_ratio(
		g_game.number[g_game.nb_kills / 10], (t_vector){-1, g_app.res.y / 7});
	put_image_in_image(g_app.img, g_game.number[g_game.nb_kills / 10],
		(t_vector){g_app.res.x - size_left.x - size_right.x, 20}, size_left);
	put_image_in_image(g_app.img, g_game.number[g_game.nb_kills % 10],
		(t_vector){g_app.res.x - size_right.x, 20}, size_right);
}

void			draw_hud(void)
{
	if (g_game.life != LIFE)
	{
		g_game.life -= LIFE_CORONA_HIT;
		put_image_in_image(g_app.img, g_game.corona,
			(t_vector){0, g_app.res.y - g_app.res.y / 7},
			keep_ratio(g_game.corona, (t_vector){-1, g_app.res.y / 7}));
	}
	put_image_in_image_center(g_app.img, g_game.reticle,
		keep_ratio(g_game.reticle,
		(t_vector){g_app.res.x / 40, g_app.res.y / 40}),
		(t_vector){0, 0});
	put_image_in_image_center_bottom(g_app.img, g_game.weapon[gun_frame()],
		keep_ratio(g_game.weapon[gun_frame()],
		(t_vector){g_app.res.x / 4, g_app.res.y / 4}),
		(t_vector){g_app.res.x / 4, 0});
	draw_life();
	draw_kills();
}
