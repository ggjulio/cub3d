/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:17:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/10 18:49:36 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(t_raycast *r, int x, t_sprite *sprite)
{
	t_vector	sprite_size;
	t_vector	y_draw ;
	int			tex_x;
	float		tex_y;
	float		step_y;
	
	(void)r;
	double inv_determinant = 1.0 / (g_game.cam.plane.x * g_game.cam.dir.y - g_game.cam.dir.x * g_game.cam.plane.y);
	t_fvector transform = create_fvector(
		inv_determinant * (g_game.cam.dir.y * sprite->pos_rel_cam.x - g_game.cam.dir.x * sprite->pos_rel_cam.y),
		inv_determinant * (-g_game.cam.plane.y * sprite->pos_rel_cam.x + g_game.cam.plane.x * sprite->pos_rel_cam.y)
		);
	
	sprite_size.x = g_app.res.x * 0.5 * (1 + transform.x / transform.y);
	sprite_size.y = abs((int)(g_app.res.y / transform.y));

//////
	y_draw.x = -sprite_size.y * (1.0 - g_game.cam.height) + g_app.res.y * g_game.cam.height;
	y_draw.y = sprite_size.y * g_game.cam.height + g_app.res.y * g_game.cam.height;
	y_draw.x = (y_draw.x < 0 ? 0 : y_draw.x);
	y_draw.y = (y_draw.y > g_app.res.y ? g_app.res.y : y_draw.y);
/////////
//(stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth);

	tex_x = (x - (-sprite_size.y * 0.5 + sprite_size.x)) * sprite->texture->img.size.x / sprite_size.y;


	step_y = (float)sprite->texture->img.size.y / (float)sprite_size.y;

	tex_y = 
		fabs(y_draw.x - g_app.res.y * g_game.cam.height + sprite_size.y * (1.0 - g_game.cam.height)) * step_y;
	ft_printf("%f\n",transform.y);
	if (transform.y > 0 && transform.y < r->perp_wall_dist)
	while (y_draw.x++ < y_draw.y)
	{
		t_color		texel = create_color(0, 130, 200, 100);
	
//		texel = get_pixel_from_image(sprite->texture->img, tex_x, (int)tex_y);

		texel.c = sprite->texture->img.pixels[ tex_x + ((int)tex_y) * sprite->texture->img.size.x];
		put_pixel(create_vector(x, y_draw.x - g_game.y_offset), 
				  add_fog(
					  texel,
					  y_draw.y));
		tex_y += step_y;
	}
}

void	draw_sprites(t_raycast *r, int x)
{
	t_list	*pop_elem;

	while (r->lst_sprite != NULL)
	{
		pop_elem = ft_lstpop_front(&(r->lst_sprite));
		draw_sprite(r, x, pop_elem->content);
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
				g_game.cam.pos));
	ft_lstadd_front(&(r->lst_sprite), ft_lstnew(new_sprite));
}

void	free_lst_sprite(void *to_free)
{
	free_sprite(to_free);
}
