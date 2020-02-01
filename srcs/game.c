/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/31 17:05:12 by juligonz         ###   ########.fr       */
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

void		load_textures(t_game *g)
{
	init_tex(&(g->north), g);
	init_tex(&(g->south), g);
	init_tex(&(g->east), g);
	init_tex(&(g->west), g);
	init_tex(&(g->ceil), g);
	init_tex(&(g->floor), g);
	init_tex(&(g->sprite), g);
}

void		destroy_game(t_game g)
{
	destroy_texture(g.north, &g);
	destroy_texture(g.south, &g);
	destroy_texture(g.east, &g);
	destroy_texture(g.west, &g);
	destroy_texture(g.ceil, &g);
	destroy_texture(g.floor, &g);
	destroy_texture(g.sprite, &g);
	//destroy_map
	if (g.app.win_ptr != NULL)
		destroy_application(g.app);
}

int			exit_game(t_game *g)
{
	(void)g;
	destroy_game(*g);
	exit(0);
	return (0);
}
