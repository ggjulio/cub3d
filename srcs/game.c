/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 22:45:46 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/20 22:58:07 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	create_game(t_app *app, t_camera camera, uint8_t *map)
{
	t_game game;

	game.app = app;
	game.camera = camera;
	game.map = map;

	return (game);
}

void	destroy_game(t_game game)
{
	destroy_application(game.app);
}
