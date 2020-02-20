/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:29:54 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/20 11:03:24 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	create_sprite(
	t_texture *texture, t_vector pos, t_fvector pos_rel_player,
	double  perp_dist_rel_player)
{
	t_sprite result;

	result.texture = texture;
	result.pos = pos;
	result.pos_rel_player = pos_rel_player;
	result.perp_dist_rel_player = perp_dist_rel_player;
	return (result);
}

t_sprite	*malloc_sprite(
	t_texture *texture, t_vector pos, t_fvector pos_rel_player,
	double  perp_dist_rel_player)
{
	t_sprite *result;

	if ((result = malloc(sizeof(t_sprite))) == NULL)
		return (NULL);
	*result = create_sprite(texture, pos, pos_rel_player,
							perp_dist_rel_player);
	return (result);
}

void		destroy_sprite(t_sprite to_destroy)
{
	(void)to_destroy;
}

void		free_sprite(t_sprite *to_free)
{
	if (to_free == NULL)
		return ;
	destroy_sprite(*to_free);
	free(to_free);
	to_free = NULL;
}

void		free_lst_sprite(void *to_free)
{
	free_sprite(to_free);
}
