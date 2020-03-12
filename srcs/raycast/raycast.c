/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:17:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 11:17:04 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_strip(t_raycast *r, int x)
{
	t_texture	*texture;

	texture = get_texture_side(r->wall_side);
	draw_ceil_floor(x, r->y_draw.x - g_game.y_offset, r->y_draw.y - g_game.y_offset);
	if (texture->is_color)
		draw_wall_is_color(x, r->y_draw.x - g_game.y_offset, r->y_draw.y - g_game.y_offset, texture->color);
	else
		draw_wall_is_texture(r, x, texture);	
	draw_sprites(r, x);
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
		{
			if (g_game.is_shoot && r->camera_x == 0)
				set_map_value(r->map.x, r->map.y, 0);
			else
				save_sprite(r);
		}
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

void 	*thread_raycasting(void *idx_thread)
{
	int			x;
	int			max;
	t_raycast	r;
	
	ft_bzero(&r, sizeof(t_raycast));
	if (NB_THREAD != 0)
	{
		x = ((long)(idx_thread) *  g_app.res.x / NB_THREAD) - 1;
		max = ((long)(idx_thread) + 1) * g_app.res.x / NB_THREAD;
	}
	else
	{
		x = -1;
		max = g_app.res.x;
	}
	while (++x <= max)
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
		r.line_height = (int)(g_app.res.y / r.perp_wall_dist);
		r.y_draw = calc_obj_y_draw(r.line_height);
		draw_strip(&r, x);
	}
	return (NULL);
}

void	raycasting(void)
{
	pthread_t threads[NB_THREAD];
	long i;
	int ret;

	if (NB_THREAD == 0)
	{
		thread_raycasting(NULL);
		return ;
	}	
	i = -1;
	while (++i < NB_THREAD)
		if ((ret = pthread_create(&threads[i], NULL, thread_raycasting, (void *)i)) != 0)
			ft_printf("Error : thread nb -> %ld", i);
	i = -1;
	while (++i < NB_THREAD)
		pthread_join(threads[i], NULL);
}

