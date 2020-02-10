/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:19:46 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/10 18:54:27 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_position(t_vector pos, char c)
{
	g_game.cam.pos.x = pos.x + 0.5;
	g_game.cam.pos.y = pos.y + 0.5;
	if (c == 'N')
		g_game.cam.dir = (t_fvector){0.0, -1.0};
	else if (c == 'S')
		g_game.cam.dir = (t_fvector){0.0, 1.0};
	else if (c == 'E')
		g_game.cam.dir = (t_fvector){1.0, 0.0};
	else if (c == 'W')
		g_game.cam.dir = (t_fvector){-1.0, 0.0};
	g_game.cam.plane = (t_fvector){
		-FOV * g_game.cam.dir.y,
		FOV * g_game.cam.dir.x,
	};
}

int		str_map_to_map(void)
{
	int i;
	int j;

	if ((g_game.map = malloc(g_game.map_len_x * g_game.map_len_y)) == NULL)
		return (ft_error("Map : map not defined ?"));
	i = 0;
	j = 0;
	while (g_game.str_map[i])
	{
		while (g_game.str_map[i] == ' ')
			i++;
		if (ft_in_charset(g_game.str_map[i], "NSWE"))
		{
			save_position(
				(t_vector){j % g_game.map_len_x, j / g_game.map_len_x},
				g_game.str_map[i]);
			g_game.map[j++] = 0;
			i++;
		}
		else
			g_game.map[j++] = g_game.str_map[i++] - '0';
	}
	return (0);
}
