/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:09:50 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/05 19:11:04 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_str_map(char *line)
{
	char	*tmp;
	size_t	line_len;

	line_len = ft_strlen(line);

	if (g_game.str_map == NULL)
	{
		if ((g_game.str_map = malloc(1)) == NULL)
			return (ft_error("malloc : Failed to allocate memory"));
		g_game.str_map[0] = '\0';
	}
	g_game.map_len_x = (line_len > g_game.map_len_x ? line_len : g_game.map_len_x);
	tmp = g_game.str_map;
	g_game.str_map = ft_strjoin(tmp, line);
	free(tmp);
	tmp = g_game.str_map;
	g_game.str_map = ft_strjoin(tmp, "\n");	
	free(tmp);
	if (line_len)
		g_game.map_len_y++;
	return (0);
}


int		valid_map_char(void)
{
	int x;
	int y;

	y = 0;
	while (y < )
	{
		x = 0;
		while ()
		{

		}
	}
	ft_in_charset(g_game.str_map[i], "NSWE")
	
}

int     valid_map(void)
{
	
}
