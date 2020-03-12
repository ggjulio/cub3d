/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:16:10 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 11:34:20 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(void)
{
	t_vector	map;
	t_fvector	ratio;
	double		r;

	r = (double)g_app.win_res.x / (double)g_app.win_res.y;
	ratio = multiply_fvec_by_scalar((t_fvector){9.0, 9.0}, r);
	map = (t_vector){-1, -1};
	while (++map.y < g_game.map_len_y)
	{
		while (++map.x < g_game.map_len_x)
		{
			draw_rectangle((t_vector){map.x * ratio.x, map.y * ratio.y},
						(t_vector){ratio.x, ratio.y},
				(map_value(map.x, map.y) == 1 ?
				create_color(65, 65, 65, 180) : create_color(222, 222, 222, 50))
);
		}
		map.x = -1;
	}
	draw_rectangle(
		(t_vector){g_game.cam.pos.x * ratio.x, g_game.cam.pos.y * ratio.y},
		(t_vector){3, 3}, create_color(231, 76, 60, 255)
);
}

uint8_t	map_value(int x, int y)
{
	return (g_game.map[x + y * g_game.map_len_x]);
}

void	set_map_value(int x, int y, uint8_t p_value)
{
	g_game.map[x + y * g_game.map_len_x] = p_value;
}
