/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:04:32 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/11 13:08:46 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef int	(*t_handler)(char **words, char *line);

int		parse_resolution(char **words, char *line)
{
	int x;
	int y;

	(void)line;
	if (count_str_arr(words) != 3 || g_game.str_map != NULL)
		return (ft_error("R : Something wrong"));
	if (!ft_isnumber(words[1]) || !ft_isnumber(words[2]))
		return (ft_error("R : Only digits plz."));
	x = ft_atoi(words[1]);
	y = ft_atoi(words[2]);
	if (g_app.res.x > 0)
		return (ft_error("R : Dupplicate id"));
	if (x < 100 || y < 100 || x > 2560 || y > 1440)
		return (ft_error("R : Resolution should be 100x100 up to 2560x1440"));
	g_app.res.x = x;
	g_app.res.y = y;
	return (0);
}

int		parse_north(char **words, char *line)
{
	(void)line;
	if (count_str_arr(words) != 2 || g_game.north.id[0]
		|| g_game.str_map != NULL)
		return (ft_error("NO : Something wrong"));
	g_game.north = create_texture(words[0], words[1]);
	if (g_game.north.is_valid)
	{
		if (g_game.north.is_bad_extention)
			return (ft_error("NO : Wrong texture extention"));
		if (init_texture(&(g_game.north)) == -1)
			return (ft_error("NO : Can't load texture."));
		return (0);
	}
	return (ft_error("NO : Invalid texture or color"));
}

int		parse_south(char **words, char *line)
{
	(void)line;
	if (count_str_arr(words) != 2 || g_game.south.id[0]
		|| g_game.str_map != NULL)
		return (ft_error("SO : Something wrong"));
	g_game.south = create_texture(words[0], words[1]);
	if (g_game.south.is_valid)
	{
		if (g_game.south.is_bad_extention)
			return (ft_error("SO : Wrong texture extention"));
		if (init_texture(&(g_game.south)) == -1)
			return (ft_error("SO : Can't load texture."));
		return (0);
	}
	return (ft_error("SO : Invalid texture or color"));
}

int		parse_west(char **words, char *line)
{
	(void)line;
	if (count_str_arr(words) != 2 || g_game.west.id[0]
		|| g_game.str_map != NULL)
		return (ft_error("WE : Something wrong"));
	g_game.west = create_texture(words[0], words[1]);
	if (g_game.west.is_valid)
	{
		if (g_game.west.is_bad_extention)
			return (ft_error("WE : Wrong texture extention"));
		if (init_texture(&(g_game.west)) == -1)
			return (ft_error("WE : Can't load texture."));
		return (0);
	}
	return (ft_error("WE : Invalid texture or color"));
}

int		parse_east(char **words, char *line)
{
	(void)line;
	if (count_str_arr(words) != 2 || g_game.east.id[0]
		|| g_game.str_map != NULL)
		return (ft_error("EA : Something wrong"));
	g_game.east = create_texture(words[0], words[1]);
	if (g_game.east.is_valid)
	{
		if (g_game.east.is_bad_extention)
			return (ft_error("EA : Wrong texture extention"));
		if (init_texture(&(g_game.east)) == -1)
			return (ft_error("EA : Can't load texture."));
		return (0);
	}
	return (ft_error("EA : Invalid texture or color"));
}
