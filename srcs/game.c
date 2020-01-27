/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/27 18:17:51 by juligonz         ###   ########.fr       */
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

void		destroy_game(t_game g)
{
	if (g.app.win_ptr != NULL)
		destroy_application(g.app);
	destroy_texture(g.north, &g);
	destroy_texture(g.south, &g);
	destroy_texture(g.east, &g);
	destroy_texture(g.west, &g);
	destroy_texture(g.ceil, &g);
	destroy_texture(g.floor, &g);
	destroy_texture(g.sprite, &g);
   //destroy_map 
}

int exit_game(t_game *g)
{
    destroy_game(*g);
	exit(0);
	return(0);
}
