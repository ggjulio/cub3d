/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:19:46 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/01 11:10:03 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_position(t_vector pos, char c, t_game *g)
{
	g->cam.pos.x = pos.x + 0.5;
	g->cam.pos.y = pos.y + 0.5;
	g->cam.plane.x = 0.0;
	g->cam.plane.y = 0.58;
	if (c == 'N')
		g->cam.dir = (t_fvector){-1.0, 0.0};
	else if (c == 'S')
		g->cam.dir = (t_fvector){1.0, 0.0};
	else if (c == 'E')
		g->cam.dir = (t_fvector){1.0, 0.0};
	else if (c == 'W')
		g->cam.dir = (t_fvector){0.0, -1.0};
}

int		str_map_to_map(t_game *g)
{
	int i;
	int j;

	if ((g->map = malloc(g->map_len_x * g->map_len_y)) == NULL)
		return (ft_error("Map : map not defined ?"));
	i = 0;
	j = 0;
	while (g->str_map[i])
	{
		while (g->str_map[i] == ' ')
			i++;
		if (ft_in_charset(g->str_map[i], "NSWE"))
		{
			save_position((t_vector){j / g->map_len_x, j % g->map_len_x},
						g->str_map[i], g);
			g->map[j++] = 0;
			i++;
		}
		else
			g->map[j++] = g->str_map[i++] - '0';
	}
	return (0);
}
