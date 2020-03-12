/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 10:04:09 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(void)
{
	init_texture(&(g_game.north));
	init_texture(&(g_game.south));
	init_texture(&(g_game.east));
	init_texture(&(g_game.west));
	init_texture(&(g_game.ceil));
	init_texture(&(g_game.floor));
	init_texture(&(g_game.sprite));
	set_opacity_image_if_color(
		g_game.sprite.img, 0,
		get_pixel_from_image(g_game.sprite.img, 0, 0)
		);

	g_game.reticle = create_image_from_xpm_no_border("tex/bonus/reticle.xpm");
    g_game.weapon = create_image_from_xpm_no_border("tex/bonus/gun1.xpm");
}

void	draw_hud(void)
{
	put_image_in_image_center(g_app.img, g_game.reticle,
		keep_ratio(g_game.reticle, (t_vector){g_app.res.x / 40, g_app.res.y / 40}),
		(t_vector){0, 0});
	put_image_in_image_center_bottom(g_app.img, g_game.weapon,
		keep_ratio(g_game.weapon, (t_vector){g_app.res.x / 4, g_app.res.y / 4}),
		(t_vector){0,0});
}

int		loop_game(void)
{
	ticks_begin();
	clear_application(create_color(0, 0, 0, 0));
	raycasting();
	if (g_game.show_map)
		draw_map();
	draw_hud();
	render_application();
	ticks_end();
	rainbow_bar();
	if (g_game.mouse_move_enabled)
		mouse_movement();
	move((g_game.is_run ? RUN_SPEED : SPEED),
		(g_game.is_run ? RUN_LAT_SPEED : LAT_SPEED),
		ROT_SPEED);
	return (0);
}

uint8_t	map_value(int x, int y)
{
	return (g_game.map[x + y * g_game.map_len_x]);
}

int		ft_error(char *e)
{
	static uint8_t first_call = 1;

	if (first_call)
	{
		ft_printf("Error\n");
		first_call = 0;
	}
	ft_printf("%s\n", e);
	return (-1);
}

int		exit_game(void)
{
	destroy_game(g_game);
	destroy_application(g_app);
	exit(0);
	return (0);
}
