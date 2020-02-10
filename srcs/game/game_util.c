/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/10 15:35:02 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		load_textures(void)
{
	init_texture(&(g_game.north));
	init_texture(&(g_game.south));
	init_texture(&(g_game.east));
	init_texture(&(g_game.west));
	init_texture(&(g_game.ceil));
	init_texture(&(g_game.floor));
	init_texture(&(g_game.sprite));
}

int			exit_game(void)
{
	destroy_game(g_game);
	destroy_application(g_app);
	exit(0);
	return (0);
}
