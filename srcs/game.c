/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 22:45:46 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/21 13:50:59 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	create_game()
{
	t_game game;

	game.app = create_application(app);
	game.camera = create_camera();
	game.map = NULL;

	return (game);
}

void	destroy_game(t_game game)
{
	destroy_application(game.app);
	// free_map();
}

void	free_game(t_game *game)
{
	destroy_game(*game);
	free(game);
}
