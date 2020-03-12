/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:17:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 18:51:58 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dda_sprite(t_raycast *r)
{
	if (g_game.is_shoot && r->camera_x == 0)
	{
		play_sound(g_game.monster_killed);
		set_map_value(r->map.x, r->map.y, 0);
	}
	else
		save_sprite(r);
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
		if (2 == map_value(r->map.x, r->map.y))
			dda_sprite(r);
		if (1 == map_value(r->map.x, r->map.y))
		{
			dda_wall(r);
			break ;
		}
	}
}
