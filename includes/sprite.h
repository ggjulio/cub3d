/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:19:17 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/14 10:29:45 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "cub3d.h"

typedef struct	s_sprite
{
	t_texture	*texture;
	t_vector	pos;
	t_fvector	distance;
}				t_sprite;

t_sprite		create_sprite(t_texture *texture, t_vector position);
t_sprite		*malloc_sprite(t_texture *texture, t_vector position);
void			destroy_sprite(t_sprite to_destroy);
void			free_sprite(t_sprite *to_free);

#endif
