/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:04:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/07 16:54:30 by juligonz         ###   ########.fr       */
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
				  add_fog(g_game.floor.color, (wall_end + g_game.y_offset > g_app.res.y ? 600 : 
											   wall_end + g_game.y_offset)));
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