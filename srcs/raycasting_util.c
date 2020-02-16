/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:04:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/16 18:01:31 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_wall_is_color(int x, int y_start, int y_end, t_color pixel)
{
	while (y_start < y_end)
		put_pixel(create_vector(x, y_start++), pixel);
}

void		draw_ceil_floor(int x, int y_end)
{
	if (y_end < 0)
		return ;
	while (y_end < g_app.res.y)
	{
		put_pixel(create_vector(x, y_end), g_game.floor.color);
		put_pixel(create_vector(x, g_app.res.y - y_end), g_game.ceil.color);
		y_end++;
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
