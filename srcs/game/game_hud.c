/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 22:29:24 by juligonz         ###   ########.fr       */
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

void			check_life(void)
{
    t_color color_str;

	if (g_game.life > 0)
		return ;
	color_str = create_color(255, 255, 255, 255);
    clear_application(
        create_color(170, 0, 0, 100));
    render_application();
    mlx_string_put(g_app.mlx_ptr, g_app.win_ptr,
				   g_app.res.x / 2.3,
				   g_app.res.y / 2.5,
				   color_str.c, "You suck ! :)");

    mlx_window_set_title(g_app.win_ptr, "You suck very much !");
	mlx_loop_hook(g_app.mlx_ptr, NULL, NULL);
}

void			draw_life(void)
{
	t_vector size;
	t_color color;
	
	color = create_color(255,0,0,255);

	size = create_vector(g_app.res.x, 15);
	size.x *= g_game.life / 100.0;
	draw_rectangle((t_vector){0, 0}, size, color);
}

void			draw_hud(void)
{
	put_image_in_image_center(g_app.img, g_game.reticle,
		keep_ratio(g_game.reticle,
		(t_vector){g_app.res.x / 40, g_app.res.y / 40}),
		(t_vector){0, 0});
	put_image_in_image_center_bottom(g_app.img, g_game.weapon[gun_frame()],
		keep_ratio(g_game.weapon[gun_frame()],
		(t_vector){g_app.res.x / 4, g_app.res.y / 4}),
		(t_vector){g_app.res.x / 4, 0});
	draw_life();
}
