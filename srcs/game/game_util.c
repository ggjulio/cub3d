/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/10 17:55:45 by juligonz         ###   ########.fr       */
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
//	g_game.reticle = create_image_from_xpm("tex/alex.xpm");
	g_game.reticle = create_image_from_xpm("tex/bonus/reticle.xpm");
	set_opacity_image(g_game.reticle, 190);
	set_opacity_image_if_color(
		g_game.reticle, 0, create_color(0, 0, 0, 0));
// need check if sprite is color
/*	set_opacity_image_if_color(
		g_game.sprite.img, 0,
		get_pixel_from_image(g_game.sprite.img, 0, 0)
		);*/
}

void	ticks_begin(void)
{
	g_game.ticks_begin = clock();
	g_game.ticks_delta = 0;
	g_game.ticks_end = 0;
	g_game.fps = 0;
}

void	ticks_end(void)
{
	g_game.ticks_end = clock();
	g_game.ticks_delta = g_game.ticks_end - g_game.ticks_begin;
	g_game.fps = get_fps(g_game.ticks_delta);
}

int		loop_game(void)
{
	ticks_begin();
	clear_application(create_color(0, 0, 0, 0));
	raycasting();
	if (g_game.show_map)
		draw_map();
	put_image_in_image_center(g_app.img, g_game.reticle,
		mul_vec_by_scalar(g_game.reticle.size, 13), (t_vector){0, 0});
	rainbow_bar();
	render_application();
	ticks_end();
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
