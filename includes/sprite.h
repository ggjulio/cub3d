/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:19:17 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/13 02:56:12 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "cub3d.h"

typedef struct	s_sprite
{
	t_texture	*texture;
	t_vector	pos;
	t_fvector	pos_rel_cam;
}				t_sprite;

/*
** sprite.c
*/
t_sprite		create_sprite(
	t_texture *texture, t_vector pos, t_fvector pos_rel_cam);
t_sprite		*malloc_sprite(
	t_texture *texture, t_vector pos, t_fvector pos_rel_cam);
void			destroy_sprite(t_sprite to_destroy);
void			free_sprite(t_sprite *to_free);

/*
** sprite_util.c
*/
void			draw_sprite(int x, t_sprite *sprite);
void			draw_sprites(t_raycast *r, int x);
void			save_sprite(t_raycast *r, t_texture *p_texture);
void			free_lst_sprite(void *to_free);

#endif
