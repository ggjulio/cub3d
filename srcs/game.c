/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/06 17:22:52 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_camera	create_camera(t_fvector position, t_fvector direction, \
						t_fvector plane)
{
	t_camera	camera;

	camera.pos = position;
	camera.dir = direction;
	camera.plane = plane;
	return (camera);
}

void		destroy_game(t_game to_destroy)
{
	destroy_texture(to_destroy.north);
	destroy_texture(to_destroy.south);
	destroy_texture(to_destroy.east);
	destroy_texture(to_destroy.west);
	destroy_texture(to_destroy.ceil);
	destroy_texture(to_destroy.floor);
	destroy_texture(to_destroy.sprite);
	free(to_destroy.map);
}

void		free_game(t_game *to_free)
{
	destroy_game(*to_free);
	free(to_free);
}



void		load_textures()
{
	init_texture(&(g_game.north));
	init_texture(&(g_game.south));
	init_texture(&(g_game.east));
	init_texture(&(g_game.west));
	init_texture(&(g_game.ceil));
	init_texture(&(g_game.floor));
	init_texture(&(g_game.sprite));
}

int			exit_game()
{
	destroy_game(g_game);
	destroy_application(g_app);
	exit(0);
	return (0);
}
