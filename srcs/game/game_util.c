/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 22:25:50 by juligonz         ###   ########.fr       */
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
		get_pixel_from_image(g_game.sprite.img, 0, 0));
	g_game.reticle = create_image_from_xpm_no_border("tex/bonus/reticle.xpm");
	g_game.weapon[0] = create_image_from_xpm_no_border("tex/bonus/gun1.xpm");
	g_game.weapon[1] = create_image_from_xpm_no_border("tex/bonus/gun2.xpm");
	g_game.weapon[2] = create_image_from_xpm_no_border("tex/bonus/gun3.xpm");
	g_game.weapon[3] = create_image_from_xpm_no_border("tex/bonus/gun4.xpm");
	g_game.weapon[4] = create_image_from_xpm_no_border("tex/bonus/gun5.xpm");
}

int		loop_game(void)
{
	ticks_begin();
	clear_application(create_color(0, 0, 0, 0));
	raycasting();
	if (g_game.show_map)
		draw_map();
	ticks_end();
	draw_hud();
	render_application();
	FMOD_System_Update(g_app.fmod_ptr);
	rainbow_bar();
	check_life();
	if (g_game.mouse_move_enabled)
		mouse_movement();
	move((g_game.is_run ? RUN_SPEED : SPEED),
		(g_game.is_run ? RUN_LAT_SPEED : LAT_SPEED),
		ROT_SPEED);
	return (0);
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
