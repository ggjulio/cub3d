/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:17:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/20 14:24:46 by juligonz         ###   ########.fr       */
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

	float		step_y = (float)texture->size.y / (float)r->line_height;
	float		tex_pos = fabs(y_start - g_app.res.y / 2.0 + r->line_height / 2.0) * step_y;

	while (y_start < r->wall_end)
	{
		t_color texel;

		tex.y = (int)tex_pos;
		texel.c = texture->pixels[(int)(tex.x + tex.y * texture->size.x)];
		texel.rgba.a = 255;
		put_pixel(create_vector(x, y_start), texel);

		tex_pos += step_y;
		y_start++;
	}
}

double	get_perp_sprite_dist(t_fvector object, t_raycast *r)
{
	double result;

	object = perp_clock_fvec(object);
	result = (object.x - g_game.cam.pos.x + (1 - r->step.x) / 2) / r->ray_dir.x;
	return (fabs(result));
}

t_vector	calculate_sprite_height(t_raycast *r, t_sprite sprite)
{
	t_vector result;

	(void)sprite;

	r->line_height = (int)(g_app.res.y / sprite.perp_dist_rel_cam);
	result.x = -r->line_height / 2 + g_app.res.y / 2;
	if (r->wall_start < 0)
		r->wall_start = 0;
	result.y = r->line_height / 2 + g_app.res.y / 2;
	if (r->wall_end >= g_app.res.y)
		r->wall_end = g_app.res.y - 1;
	return (result);
}

void	draw_sprite(t_raycast *r, int x)
{

//    if (r->wall_side == West || r->wall_side == East)
        r->wall_x = g_game.cam.pos.y + r->perp_wall_dist * r->ray_dir.y;
//    else
//        r->wall_x = g_game.cam.pos.x + r->perp_wall_dist * r->ray_dir.x;
    r->wall_x -= floor(r->wall_x);

	while (r->lst_sprite != NULL)
	{
		t_list		*pop_elem = ft_lstpop_front(&(r->lst_sprite));
		t_sprite	*actual = pop_elem->content;
		t_vector	height = calculate_sprite_height(r, *actual);
		t_vector	tex;

		tex.x = (int)(r->wall_x * actual->texture->size.x);

		actual->line_height = (int)(g_app.res.y / actual->perp_dist_rel_cam);

		float		step_y = (float)actual->texture->size.y / (float)actual->line_height;
		float		tex_pos = fabs(height.x - g_app.res.y / 2.0 + actual->pos.y / 2.0) * step_y;

		
		while (height.x++ < height.y)
		{
			t_color		texel;

			tex.y = (int)tex_pos;
			texel.c = actual->texture->pixels[tex.x + tex.y * actual->texture->size.x];
			texel.rgba.a = 255;
			put_pixel(create_vector(x, height.x), texel);
			tex_pos += step_y;
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
	t_sprite *new_sprite;

	new_sprite = 
		malloc_sprite(&(g_game.sprite),
			r->map,
			sub_fvec_by_fvec(
				add_scalar_to_fvec(0.5, vec_to_fvec(r->map)),
				g_game.cam.pos),
			get_perp_sprite_dist(
					sub_fvec_by_fvec(vec_to_fvec(r->map), g_game.cam.pos), r)
			);

/*	ft_printf("pos(%d, %d)  ||  ", new_sprite->pos.x, new_sprite->pos.y);
	ft_printf("pos_rel_player(%f, %f) ||", new_sprite->pos_rel_cam.x, new_sprite->pos_rel_cam.y);
	ft_printf("perp_dist_rel_player = %f\n", new_sprite->perp_dist_rel_cam);
*/
	ft_lstadd_front(&(r->lst_sprite), ft_lstnew(new_sprite));
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
	r->wall_start = (r->wall_start < 0 ? 0 : r->wall_start);
	r->wall_end = r->line_height / 2 + g_app.res.y / 2;
	r->wall_end = (r->wall_end > g_app.res.y ? g_app.res.y : r->wall_end);
}

void	raycasting(void)
{
	int			x;
	t_raycast	r;

	x = -1;
	ft_bzero(&r, sizeof(t_raycast));
	while (++x <= g_app.res.x)
	{
		r.camera_x = 2 * x / (double)(g_app.res.x) - 1;
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
