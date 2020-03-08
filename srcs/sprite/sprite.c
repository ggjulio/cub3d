/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:29:54 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/08 15:36:45 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	create_sprite(
	t_texture *texture, t_vector pos, t_fvector pos_rel_cam)
{
	t_sprite result;

	result.texture = texture;
	result.pos = pos;
	result.pos_rel_cam = pos_rel_cam;
	return (result);
}

t_sprite	*malloc_sprite(
	t_texture *texture, t_vector pos, t_fvector pos_rel_cam)
{
	t_sprite *result;

	if ((result = malloc(sizeof(t_sprite))) == NULL)
		return (NULL);
	*result = create_sprite(texture, pos, pos_rel_cam);
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
