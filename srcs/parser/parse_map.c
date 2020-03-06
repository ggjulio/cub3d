/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:09:50 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/06 13:59:55 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		valid_map_char(void)
{
	int i;

	i = -1;
	while (++i < g_game.map_len_x * g_game.map_len_y)
	{
		if (!ft_in_charset(g_game.map[i] + '0', "NSWE 012"))
			return (ft_error("Map : Only \"NSWE 012\" are allowed in the map"));
	}
	return (0);
}



int		valid_map_closed_map(void)
{
	int x;
	int y;

	x = -1;
	while (++x < g_game.map_len_x)
	{
		ft_printf("1|%c|%d,%d|\n", map_value(x, 0) + '0', x, g_game.map_len_y - 1);
		ft_printf("2|%c|%d,%d|\n", map_value(x, g_game.map_len_y - 1) + '0', x, g_game.map_len_y - 1);
		if (!ft_in_charset((map_value(x, 0) + '0'), " 1") ||
			!ft_in_charset((map_value(x, g_game.map_len_y - 1) + '0'), " 1"))
		{
			return (ft_error("Map : Maps no well closed"));		
		}
	}

	y = 0;
	while (++y < g_game.map_len_y - 1)
	{
//		if (!ft_in_charset((map_value(x, y) + '0'), "1 "))
//			return (ft_error("Map : Maps no well closed"));
		x = 0;
		while (++x < g_game.map_len_x - 1)
		{
//			ft_printf("|%c|%d,%d|\n", map_value(x, y) + '0', x, y);
			if (ft_in_charset((map_value(x, y) + '0'), "02NSWE"))
				if ((char)map_value(x - 1, y) + '0' == ' ' ||
					(char)map_value(x + 1, y) + '0' == ' ' ||
					(char)map_value(x, y - 1) + '0' == ' ' ||
					(char)map_value(x, y + 1) + '0' == ' ')
					return (ft_error("Map : Maps no well closed"));
		}
	}
	return (0);
}



int     valid_map(void)
{
//	if (//valid_map_char() == -1 ||
		//valid_map_closed_map() == -1) 
	
//		return (-1);
	return (0);
}

