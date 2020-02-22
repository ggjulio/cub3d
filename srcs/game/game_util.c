/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/22 15:21:26 by juligonz         ###   ########.fr       */
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
}


void    draw_map(void)
{
    t_vector map;
	int ratio = 9;

    map = (t_vector){-1, -1};
	while (++map.y < g_game.map_len_y)
	{
		while (++map.x < g_game.map_len_x)
		{
			draw_rectangle((t_vector){map.x * ratio, map.y * ratio},
						   (t_vector){ratio, ratio}, 
				(map_value(map.x, map.y) == 1 ?
				 create_color(65,65,65, 100) :  create_color(222, 222, 222, 100)));
		}
		map.x = -1;
	}
	draw_rectangle((t_vector){g_game.cam.pos.x * ratio, g_game.cam.pos.y * ratio},
				   (t_vector){3, 3}, create_color(231, 76, 60, 255));
}

int		loop_game(void)
{
	clear_application(create_color(0, 0, 0, 0));
	if (g_game.mouse_move_enabled)
		mouse_movement();
	move((g_game.is_run ? RUN_SPEED : SPEED),
		(g_game.is_run ? RUN_LAT_SPEED : LAT_SPEED),
		ROT_SPEED);
	raycasting();
	if (g_game.show_map)
		draw_map();
	render_application();
	rainbow_bar();
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
