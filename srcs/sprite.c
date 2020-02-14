/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:29:54 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/14 10:35:39 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	create_sprite(t_texture *texture, t_vector position)
{
	t_sprite result;

	result.texture = texture;
	result.pos = position;
	return (result);
}

t_sprite	*malloc_sprite(t_texture *texture, t_vector position)
{
	t_sprite *sprite;

	if ((sprite = malloc(sizeof(sprite))) == NULL)
		return (NULL);
	*sprite = create_sprite(texture, position);
	return (sprite);
}

void		destroy_sprite(t_sprite to_destroy)
{
	(void)to_destroy;
}

void		free_sprite(t_sprite *to_free)
{
	destroy_sprite(*to_free);
	free(to_free);
}
