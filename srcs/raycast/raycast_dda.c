/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:17:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/13 03:06:25 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dda_sprite(t_raycast *r, uint8_t value)
{
	if (value == 3)
		save_sprite(r, &(g_game.sprite_medic));
	else if (g_game.is_shoot && r->camera_x == 0)
	{
		play_sound(g_game.monster_killed);
		set_map_value(r->map.x, r->map.y, 0);
		g_game.nb_kills++;
	}
	else
		save_sprite(r, &(g_game.sprite));
}

static void	dda_wall(t_raycast *r)
{
	if (r->side)
		r->wall_side = (r->ray_dir.x < 0.0 ? West : East);
	else
		r->wall_side = (r->ray_dir.y < 0.0 ? North : South);
}

static void	prehit_wall(t_raycast *r)
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

void		dda(t_raycast *r)
{
	prehit_wall(r);
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
		if (2 == map_value(r->map.x, r->map.y) ||
			3 == map_value(r->map.x, r->map.y))
			dda_sprite(r, map_value(r->map.x, r->map.y));
		if (1 == map_value(r->map.x, r->map.y))
		{
			dda_wall(r);
			break ;
		}
	}
}
