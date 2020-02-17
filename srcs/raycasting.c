/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:17:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/17 14:16:26 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall_is_texture(t_raycast *r, int x, t_texture *texture)
{
	t_vector	tex;
	int			y_start;

	y_start = r->wall_start;
	if (r->wall_side == West || r->wall_side == East)
		r->wall_x = g_game.cam.pos.y + r->perp_wall_dist * r->ray_dir.y;
	else
		r->wall_x = g_game.cam.pos.x + r->perp_wall_dist * r->ray_dir.x;
	r->wall_x -= floor(r->wall_x);

	tex.x = (int)(r->wall_x * texture->size.x);

	double		step_y = (double)texture->size.y / (double)r->line_height;
	double		tex_pos = fabs(y_start - g_app.res.y / 2.0 + r->line_height / 2.0) * step_y;
	while (y_start < r->wall_end)
	{
		tex.y = (int)tex_pos;
		tex_pos += step_y;
		t_color texel;
		texel.c = texture->pixels[(int)(tex.x + tex.y * texture->size.x)];
		texel.rgba.a = 255;
		put_pixel(create_vector(x, y_start), texel);
		tex.y += tex_pos;
		y_start++;
	}
}

void	draw_sprite(t_raycast *r, int x)
{
	t_list *pop_elem = NULL;
	t_sprite *actual;

	t_vector	tex;

	t_color		texel;
	int			y_start = r->wall_start;

    if (r->wall_side == West || r->wall_side == East)
        r->wall_x = g_game.cam.pos.y + r->perp_wall_dist * r->ray_dir.y;
    else
        r->wall_x = g_game.cam.pos.x + r->perp_wall_dist * r->ray_dir.x;
    r->wall_x -= floor(r->wall_x);


	while (r->lst_sprite != NULL)
	{
		pop_elem = ft_lstpop_front(&(r->lst_sprite));
		actual = pop_elem->content;


		tex.x = (int)(r->wall_x * actual->texture->size.x);

		
		texel.c = actual->texture->pixels[tex.x + tex.y * actual->texture->size.x];
		while (y_start++ < r->wall_end)
		{

			put_pixel(create_vector(x, y_start), texel);
		}

		ft_lstdelone(pop_elem, free_lst_sprite);
	}
}

void	draw_strip(t_raycast *r, int x)
{
	t_texture	*texture;

	texture = get_texture_side(r->wall_side);
	draw_ceil_floor(x, r->wall_end);
	if (texture->is_color)
		draw_wall_is_color(x, r->wall_start, r->wall_end, texture->color);
	else
		draw_wall_is_texture(r, x, texture);
	draw_sprite(r, x);
}



void	save_sprite(t_raycast *r)
{
	ft_lstadd_front(&(r->lst_sprite),
					ft_lstnew(
						malloc_sprite(&(g_game.sprite),
									  r->map,
									  sub_fvec_by_fvec(g_game.cam.pos, vec_to_fvec(r->map))
							)
						)
		);
}

void	prehit_wall(t_raycast *r)
{
	if (r->ray_dir.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x = (g_game.cam.pos.x - r->map.x) * r->delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		r->side_dist.x = (r->map.x + 1.0 - g_game.cam.pos.x) * r->delta_dist.x;
	}
	if (r->ray_dir.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y = (g_game.cam.pos.y - r->map.y) * r->delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		r->side_dist.y = (r->map.y + 1.0 - g_game.cam.pos.y) * r->delta_dist.y;
	}
}

void	dda(t_raycast *r)
{
	uint8_t map_v;

	while (1)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta_dist.x;
			r->map.x += r->step.x;
			r->side = 1;
		}
		else
		{
			r->side_dist.y += r->delta_dist.y;
			r->map.y += r->step.y;
			r->side = 0;
		}
		map_v = map_value(r->map.x, r->map.y);
		if (map_v == 2)
			save_sprite(r);
		if (map_v == 1)
		{
			if (r->side)
				r->wall_side = (r->ray_dir.x < 0.0 ? West : East);
			else
				r->wall_side = (r->ray_dir.y < 0.0 ? North : South);
			break ;
		}
	}
}

void	fix_fisheye(t_raycast *r)
{
	if (r->side == 1)
		r->perp_wall_dist =
			(r->map.x - g_game.cam.pos.x + (1 - r->step.x) / 2) / r->ray_dir.x;
	else
		r->perp_wall_dist =
			(r->map.y - g_game.cam.pos.y + (1 - r->step.y) / 2) / r->ray_dir.y;
}

void	calculate_wall_height(t_raycast *r)
{
	r->line_height = (int)(g_app.res.y / r->perp_wall_dist);
	r->wall_start = -r->line_height / 2 + g_app.res.y / 2;
	if (r->wall_start < 0)
		r->wall_start = 0;
	r->wall_end = r->line_height / 2 + g_app.res.y / 2;
	if (r->wall_end >= g_app.res.y)
		r->wall_end = g_app.res.y - 1;
}

void	raycasting(void)
{
	int			x;
	t_raycast	r;

	x = -1;
	ft_bzero(&r, sizeof(t_raycast));
	while (++x <= g_app.res.x)
	{
		r.camera_x = 2 * x / (double)(g_app.res.y) - 1;
		r.ray_dir = (t_fvector){
			g_game.cam.dir.x + g_game.cam.plane.x * r.camera_x,
			g_game.cam.dir.y + g_game.cam.plane.y * r.camera_x};
		r.map = (t_vector){(int)g_game.cam.pos.x, (int)g_game.cam.pos.y};
		r.delta_dist =
			(t_fvector){fabs(1 / r.ray_dir.x), fabs(1 / r.ray_dir.y)};
		prehit_wall(&r);
		dda(&r);
		fix_fisheye(&r);
		calculate_wall_height(&r);
		draw_strip(&r, x);
	}
}
