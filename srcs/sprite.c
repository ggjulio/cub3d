/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:29:54 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/14 17:00:21 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	create_sprite(
	t_texture *texture, t_vector pos_int, t_fvector pos_dbl, t_fvector dist_from_cam)
{
	t_sprite result;

	result.texture = texture;
	result.pos_int = pos_int;
	result.pos_dbl = pos_dbl;
	result.dist_from_cam = dist_from_cam;
	return (result);
}

t_sprite	*malloc_sprite(
				t_texture *texture, t_vector position, t_fvector distance)
{
	t_sprite *result;

	if ((result = malloc(sizeof(t_sprite))) == NULL)
		return (NULL);
	*result = create_sprite(texture, position, distance);
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
