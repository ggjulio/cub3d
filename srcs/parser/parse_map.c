/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:09:50 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/13 03:56:32 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		valid_position(void)
{
	int i;
	int is_pos;

	is_pos = 0;
	i = -1;
	while (g_game.str_map[++i])
	{
		if (ft_in_charset(g_game.str_map[i], "NSWE"))
		{
			if (is_pos)
				return (ft_error("Map : Several definition of start position"));
			is_pos = 1;
		}
	}
	if (!is_pos)
		return (ft_error("Map : No start position defined"));
	return (0);
}

int		valid_map_char(void)
{
	int i;

	i = -1;
	while (++i < g_game.map_len_x * g_game.map_len_y)
		if (!ft_in_charset(g_game.map[i] + '0', VALID_CHAR_MAP))
			return (ft_error("Map: Only \"NSWE 0123\" are allowed in the map"));
	return (0);
}

int		valid_map_closed_map(void)
{
	int x;
	int y;

	x = -1;
	while (++x < g_game.map_len_x)
		if (!ft_in_charset((map_value(x, 0) + '0'), " 1") ||
			!ft_in_charset((map_value(x, g_game.map_len_y - 1) + '0'), " 1"))
			return (ft_error("Map : Map not well closed"));
	y = 0;
	while (++y < g_game.map_len_y - 1)
	{
		if (!ft_in_charset((map_value(0, y) + '0'), "1 ") ||
			!ft_in_charset((map_value(g_game.map_len_x - 1, y) + '0'), "1 "))
			return (ft_error("Map : Maps not well closed"));
		x = 0;
		while (++x < g_game.map_len_x - 1)
			if (ft_in_charset((map_value(x, y) + '0'), "023NSWE"))
				if ((char)map_value(x - 1, y) + '0' == ' ' ||
					(char)map_value(x + 1, y) + '0' == ' ' ||
					(char)map_value(x, y - 1) + '0' == ' ' ||
					(char)map_value(x, y + 1) + '0' == ' ')
					return (ft_error("Map : Maps not well closed"));
	}
	return (0);
}

int		valid_map_all_ids(void)
{
	if (g_app.res.x < 0 || !g_game.north.id[0] || !g_game.south.id[0] ||
		!g_game.east.id[0] || !g_game.west.id[0] ||
		!g_game.ceil.id[0] || !g_game.floor.id[0] || !g_game.sprite.id[0])
		return (ft_error("File : Missing ids"));
	return (0);
}

int		valid_map(void)
{
	if (!g_game.map_len_x && !g_game.map_len_y)
		return (ft_error("Map : No map. You suck."));
	if (valid_map_all_ids() == -1 ||
		valid_position() == -1 ||
		valid_map_char() == -1 ||
		valid_map_closed_map() == -1)
		return (-1);
	return (0);
}
