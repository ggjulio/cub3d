/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/16 15:54:10 by juligonz         ###   ########.fr       */
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

int		loop_game(void)
{
	clear_application(create_color(0, 0, 0, 0));
	if (g_game.mouse_move_enabled)
		mouse_movement();
	move((g_game.is_run ? RUN_SPEED : SPEED),
		(g_game.is_run ? RUN_LAT_SPEED : LAT_SPEED),
		ROT_SPEED);
	raycasting();
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
