/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/13 02:34:20 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game		create_game(void)
{
	t_game result;

	ft_bzero(&result, sizeof(t_game));
	result.life = LIFE;
	return (result);
}

t_game		*malloc_game(void)
{
	t_game *result;

	if ((result = malloc(sizeof(t_game))) == NULL)
		return (NULL);
	*result = create_game();
	return (result);
}

static void	destroy_number(t_game to_destroy)
{
	destroy_image(to_destroy.number[0]);
	destroy_image(to_destroy.number[1]);
	destroy_image(to_destroy.number[2]);
	destroy_image(to_destroy.number[3]);
	destroy_image(to_destroy.number[4]);
	destroy_image(to_destroy.number[5]);
	destroy_image(to_destroy.number[6]);
	destroy_image(to_destroy.number[7]);
	destroy_image(to_destroy.number[8]);
	destroy_image(to_destroy.number[9]);
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
	destroy_image(to_destroy.reticle);
	destroy_image(to_destroy.weapon[0]);
	destroy_image(to_destroy.weapon[1]);
	destroy_image(to_destroy.weapon[2]);
	destroy_image(to_destroy.weapon[3]);
	destroy_image(to_destroy.weapon[4]);
	destroy_image(to_destroy.corona);
	destroy_image(to_destroy.health_bar);
	destroy_sound(to_destroy.shoot);
	destroy_sound(to_destroy.snapshot);
	destroy_sound(to_destroy.monster_killed);
	destroy_sound(to_destroy.ambiance);
	destroy_sound(to_destroy.game_over);
	destroy_number(to_destroy);
	free(to_destroy.map);
	free(to_destroy.str_map);
}

void		free_game(t_game *to_free)
{
	destroy_game(*to_free);
	free(to_free);
}
