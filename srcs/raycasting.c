/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:17:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/22 15:15:27 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color add_sunset(t_color pixel, int y, int y_start)
{
	t_color result;
	t_color sunset;
	int		p;

	(void)y_start;
	(void)y;
	p = ((g_app.res.y / 2 - (y_start + 1)) - y_start);
	
	sunset = create_color(200, 50, 50, 0);
	sunset.rgba.a = p * 255 / (g_app.res.y);
	result = combine_color(pixel, sunset);
	result.rgba.a = pixel.rgba.a;
	return (result);
}

t_color add_fog(t_color pixel, int y_end)
{
	t_color result;
	t_color fog;
	int		p = ((g_app.res.y - (y_end + 1)) - y_end);
//	int		p = g_app.res.y - y_end + 1;

	fog = g_game.fog_color;
	fog.rgba.a = p * 255 / (g_app.res.y);
	fog.rgba.a *= g_game.fog_ratio;

	result = combine_color(pixel, fog);
	result.rgba.a = pixel.rgba.a;
	return (result);
}

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
	float		tex_pos = fabs(y_start - g_app.res.y * g_game.cam.height + r->line_height * (1.0 - g_game.cam.height)) * step_y;

	while (y_start < r->wall_end)
	{
		t_color texel;

		tex.y = (int)tex_pos;
		texel.c = texture->pixels[(int)(tex.x + tex.y * texture->size.x)];
		texel.rgba.a = 255;

		put_pixel(create_vector(x, y_start - (r->wall_end - y_start == g_app.res.y ?  0 : g_game.y_offset)), 
				  add_fog(texel, r->wall_end));

		tex_pos += step_y;
		y_start++;
	}
}

void	draw_sprite(t_raycast *r, int x)
{

	while (r->lst_sprite != NULL)
	{
		t_list		*pop_elem = ft_lstpop_front(&(r->lst_sprite));
		t_sprite	*actual = pop_elem->content;
		t_vector	height = (t_vector){100, 400};
		t_vector	tex;

		tex.x = (int)(r->wall_x * actual->texture->size.x);

		while (height.x++ < height.y)
		{
			t_color		texel = create_color(0, 130, 200, 100);


			put_pixel(create_vector(x, height.x), texel);
		}
		
		ft_lstdelone(pop_elem, free_lst_sprite);
	}
}

void	draw_strip(t_raycast *r, int x)
{
	t_texture	*texture;

	texture = get_texture_side(r->wall_side);
	draw_ceil_floor(x, r->wall_start - g_game.y_offset, r->wall_end - g_game.y_offset);
	if (texture->is_color)
		draw_wall_is_color(x, r->wall_start - g_game.y_offset, r->wall_end - g_game.y_offset, texture->color);
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
				g_game.cam.pos)
			);
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
	r->wall_start = -r->line_height * (1.0 - g_game.cam.height) + g_app.res.y * g_game.cam.height;
	r->wall_start = (r->wall_start < 0 ? 0 : r->wall_start);
	r->wall_end = r->line_height * g_game.cam.height + g_app.res.y * g_game.cam.height;
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
