/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:04:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/10 13:14:49 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_wall_is_color(int x, int y_start, int y_end, t_color pixel)
{
	while (y_start < y_end)
	{
		put_pixel(create_vector(x, y_start), add_fog(pixel, y_end));
		y_start++;
	}
}

void		draw_wall_is_texture(t_raycast *r, int x, t_texture *texture)
{
	int		tex_x;
	float	tex_y;
	int		y_start;
	float	step_y;

	y_start = r->wall_start;
	if (r->wall_side == West || r->wall_side == East)
		r->wall_x = g_game.cam.pos.y + r->perp_wall_dist * r->ray_dir.y;
	else
		r->wall_x = g_game.cam.pos.x + r->perp_wall_dist * r->ray_dir.x;
	r->wall_x -= floor(r->wall_x);
	tex_x = (int)(r->wall_x * texture->img.size.x);
	step_y = (float)texture->img.size.y / (float)r->line_height;
	tex_y = fabs(y_start - g_app.res.y * g_game.cam.height +
			r->line_height * (1.0 - g_game.cam.height)) * step_y;
	while (y_start < r->wall_end)
	{
		put_pixel(
			create_vector(x, y_start - g_game.y_offset),
			add_fog(
				get_pixel_from_image(texture->img, tex_x, (int)tex_y),
				r->wall_end));
		tex_y += step_y;
		y_start++;
	}
}

void		draw_ceil_floor(int x, int wall_start, int wall_end)
{
	int		i;
	t_color	ceil;

	if (wall_end < 0)
		return ;
	ceil = g_game.ceil.color;
	i = -1;
	while (++i < wall_start)
	{
		ceil = g_game.is_sunset ? add_sunset(g_game.ceil.color, i, 0) : ceil;
		ceil =
		g_game.is_fog_on_ceil ? add_fog(g_game.ceil.color, wall_end + i) : ceil;
		put_pixel(create_vector(x, i), ceil);
	}
	while (wall_end < g_app.res.y)
	{
		put_pixel(create_vector(x, wall_end),
		add_fog(g_game.floor.color, (wall_end + g_game.y_offset > g_app.res.y ?
						600 : wall_end + g_game.y_offset)));
		wall_end++;
	}
}

t_texture	*get_texture_side(enum e_direction dir)
{
	if (dir == North)
		return (&g_game.north);
	else if (dir == South)
		return (&g_game.south);
	else if (dir == East)
		return (&g_game.east);
	else if (dir == West)
		return (&g_game.west);
	return (NULL);
}
