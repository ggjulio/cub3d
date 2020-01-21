/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 22:45:46 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/21 17:42:40 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	create_game(t_application app, t_camera cam, uint8_t *map)
{
	t_game game;

	game.app = app;
	game.cam = cam;
	game.map = map;

	return (game);
}

void	destroy_game(t_game game)
{
	destroy_application(game.app);
	destroy_camera(game.cam);
	// free_map();
}
