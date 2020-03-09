/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/09 15:53:45 by juligonz         ###   ########.fr       */
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
	g_game.reticle = create_image_from_xpm("tex/alex.xpm");
//	g_game.reticle = create_image_from_xpm("tex/bonus/reticle.xpm");
	set_opacity_image(g_game.reticle, 190);
	set_opacity_image_if_color(
		g_game.reticle, 0, create_color(255, 255, 255, 0));
}

/*
** units/(units/time) => time (seconds) * 1000 = milliseconds
*/
double clockToMilliseconds(clock_t ticks){
	return (ticks * 1000 / CLOCKS_PER_SEC);
}

double clockToSeconds(clock_t ticks){
	return ((double)ticks / (double)CLOCKS_PER_SEC);
}

int		loop_game(void)
{
////////////////////////////
	g_game.ticks_begin = clock();
///////////////////////////

	clear_application(create_color(0, 0, 0, 0));
	raycasting();
	if (g_game.show_map)
		draw_map();
	put_image_in_image_center(g_app.img, g_game.reticle,
		div_vec_by_scalar(g_game.reticle.size, 13), (t_vector){0, 0});
	rainbow_bar();


//////////////////////////////////////
	g_game.ticks_end = clock();
	g_game.ticks_delta = g_game.ticks_end - g_game.ticks_begin;
	if (g_game.ticks_delta > 0)
		g_game.fps = CLOCKS_PER_SEC / g_game.ticks_delta;
	unsigned long millis = clockToMilliseconds((g_game.ticks_end - g_game.ticks_begin)); 
	ft_printf( "%ld ms| ||%f|| fps: %d^^^", millis, millis / 100.0, g_game.fps);
/////////////////////////////////////////

	double frametime = clockToSeconds((g_game.ticks_end - g_game.ticks_begin));


	

	ft_printf("||%.15f\n", frametime);


	if (g_game.mouse_move_enabled)
		mouse_movement();
	move((g_game.is_run ? RUN_SPEED * frametime : SPEED * frametime),
		(g_game.is_run ? RUN_LAT_SPEED * frametime : LAT_SPEED * frametime),
		ROT_SPEED * frametime);
	render_application();
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
