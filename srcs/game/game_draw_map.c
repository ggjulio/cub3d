/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:16:10 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/23 16:16:29 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_map(void)
{
	t_vector map;
	t_vector ratio = (t_vector){9, 9};

	double r = (double)g_app.win_res.x / (double)g_app.win_res.y;
	(void)r;

//	ft_printf("%f  || %d || %d  ||", r, g_app.win_res.x, g_app.win_res.y);
	ratio.x *= r;
	ratio.y *= r;

//	ft_printf(" || (%d,%d)\n", ratio.x, ratio.y);

    map = (t_vector){-1, -1};
	while (++map.y < g_game.map_len_y)
	{
		while (++map.x < g_game.map_len_x)
		{
			draw_rectangle((t_vector){map.x * ratio.x, map.y * ratio.y},
						   (t_vector){ratio.x, ratio.y}, 
				(map_value(map.x, map.y) == 1 ?
				 create_color(65,65,65, 180) :  create_color(222, 222, 222, 50)));
		}
		map.x = -1;
	}
	draw_rectangle((t_vector){g_game.cam.pos.x * ratio.x, g_game.cam.pos.y * ratio.y},
				   (t_vector){3, 3}, create_color(231, 76, 60, 255));
}
