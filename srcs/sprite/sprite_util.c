/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:17:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/10 11:20:52 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(t_raycast *r, int x)
{

	while (r->lst_sprite != NULL)
	{
		t_list		*pop_elem = ft_lstpop_front(&(r->lst_sprite));
		t_sprite	*actual = pop_elem->content;
		t_vector	s_size;
		t_vector	draw ;
		t_vector	tex;


		double inv_determinant =
			1.0 / g_game.cam.dir.y * g_game.cam.pos.x - g_game.cam.dir.x * g_game.cam.pos.y;
		t_fvector transform = create_fvector(
			inv_determinant * (g_game.cam.dir.y * actual->pos_rel_cam.x - g_game.cam.dir.x * actual->pos_rel_cam.y),
			inv_determinant * (-g_game.cam.plane.y * actual->pos_rel_cam.x - g_game.cam.plane.x * actual->pos_rel_cam.y)
			);

		s_size.x = g_app.res.x * 0.5 * (1 + transform.x / transform.y);
		s_size.y = g_app.res.y / transform.y;

//////
		draw.x = - s_size.y * 0.5 + g_app.res.y * 0.5;
		draw.y = s_size.y * 0.5 + g_app.res.y * 0.5;
			

/////////
		tex.x = r->wall_x * actual->texture->img.size.x;
		while (draw.x++ < draw.y)
		{
			t_color		texel = create_color(0, 130, 200, 100);

//			texel.c = get_pixel_from_image(actual->texture.img, x, y);


			put_pixel(create_vector(x, draw.x), texel);
		}
		ft_lstdelone(pop_elem, free_lst_sprite);
	}
}

void	save_sprite(t_raycast *r)
{
	t_sprite *new_sprite;

	new_sprite = 
		malloc_sprite(&(g_game.sprite),
			r->map,
			sub_fvec_by_fvec(
				add_scalar_to_fvec(0.5, vec_to_fvec(r->map)),
				g_game.cam.pos)
			);
	ft_lstadd_front(&(r->lst_sprite), ft_lstnew(new_sprite));
}

void	free_lst_sprite(void *to_free)
{
	free_sprite(to_free);
}
