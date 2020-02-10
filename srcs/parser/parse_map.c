/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:09:50 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/10 15:07:06 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		valid_map_first_line(void)
{
	int i;
	int len;
	int nb_one;

	i = 0;
	len = 0;
	nb_one = 0;
	while (len < g_game.map_len_x)
	{
		if (g_game.str_map[i] != ' ')
			len++;
		if (g_game.str_map[i] == '1')
			nb_one++;
		i++;
	}
	if (nb_one == g_game.map_len_x)
		return (1);
	return (ft_error("Map : Invalid first line."));
}

int		valid_map_last_line(void)
{
	int i;
	int len;
	int nb_one;

	if (g_game.str_map == NULL)
		return (ft_error("Map : map not defined ?"));
	i = ft_strlen(g_game.str_map) - 1;
	len = 0;
	nb_one = 0;
	while (len < g_game.map_len_x)
	{
		if (g_game.str_map[i] != ' ')
			len++;
		if (g_game.str_map[i] == '1')
			nb_one++;
		i--;
	}
	if (nb_one == g_game.map_len_x)
		return (1);
	return (ft_error("Map : Invalid last line."));
}

int		valid_map(void)
{
	int i;
	int is_pos;

	if (valid_map_first_line() == -1 || valid_map_last_line() == -1)
		return (-1);
	if (!g_app.res.x || !g_game.north.id[0] || !g_game.south.id[0] ||
		!g_game.east.id[0] || !g_game.west.id[0] ||
		!g_game.ceil.id[0] || !g_game.floor.id[0] || !g_game.sprite.id[0])
		return (ft_error("File : Missing ids"));
	i = -1;
	is_pos = 0;
	while (g_game.str_map[++i])
		if (ft_in_charset(g_game.str_map[i], "NSWE"))
		{
			is_pos = 1;
			break ;
		}
	if (!is_pos)
		return (ft_error("Map : No start position defined"));
	return (0);
}

int		valid_line(char *line)
{
	static uint8_t	is_pos;
	int				i;
	char			*tmp;

	i = 0;
	while (line[++i])
	{
		if (ft_in_charset(line[i], "NSEW"))
		{
			if (is_pos)
				return (ft_error("Map : Several definition of start position"));
			is_pos = 1;
		}
		if (!ft_in_charset(line[i], "012NSEW "))
			return (ft_error("Map : Bad character in the map"));
	}
	i = 0;
	tmp = ft_strrchr(line, '1');
	while (tmp[++i])
		if (tmp[i] != ' ')
			return (ft_error("Map : Map not closed at right side"));
	return (1);
}

int		parse_str_map(char **words, char *line)
{
	char	*tmp;

	(void)words;
	if (g_game.str_map == NULL)
	{
		if ((g_game.str_map = malloc(1)) == NULL)
			return (ft_error("malloc : Failed to allocate memory"));
		g_game.str_map[0] = '\0';
		g_game.map_len_x = ft_strlen_charset(line, "012NSWE");
	}
	else if (ft_strlen_charset(line, "012NSWE") != g_game.map_len_x)
		return (ft_error("Map : Different len"));
	if (g_game.map_len_x < 3)
		return (ft_error("Map : Minimal size is 3 by 3"));
	if (valid_line(line) == -1)
		return (-1);
	tmp = g_game.str_map;
	g_game.str_map = ft_strjoin(tmp, line);
	free(tmp);
	g_game.map_len_y++;
	return (0);
}
