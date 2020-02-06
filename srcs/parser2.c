/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:04:32 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/06 16:43:54 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef int	(*t_handler)(char **words, char *line, t_game *g);

int		parse_resolution(char **words, char *line, t_game *g)
{
	int x;
	int y;

	(void)line;
	if (count_str_arr(words) != 3 || g->str_map != NULL)
		return (ft_error("R : Something wrong"));
	if (!ft_isnumber(words[1]) || !ft_isnumber(words[2]))
		return (ft_error("R : Only digits plz."));
	x = ft_atoi(words[1]);
	y = ft_atoi(words[2]);
	if (x < 100 || y < 100 || x > 2560 || y > 1440)
		return (ft_error("R : Resolution should be 100x100 up to 2560x1440"));
	if (g->app.res.x)
		return (ft_error("R : Dupplicate id"));
	g->app.res.x = x;
	g->app.res.y = y;
	g->app = create_application(g->app.res.x, g->app.res.y, "Cub3D");
	return (0);
}

int		parse_north(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_str_arr(words) != 2 || g->north.id[0] || g->str_map != NULL)
		return (ft_error("NO : Something wrong"));
	g->north = create_texture(words[0], words[1]);
	if (g->north.is_valid)
	{
		if (g->north.is_bad_extention)
			return (ft_error("NO : Wrong texture extention"));
		if (init_texture(&(g->north), g) == -1)
			return (ft_error("NO : Can't load texture."));
		return (0);
	}
	return (ft_error("NO : Invalid texture or color"));
}

int		parse_south(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_str_arr(words) != 2 || g->south.id[0] || g->str_map != NULL)
		return (ft_error("SO : Something wrong"));
	g->south = create_texture(words[0], words[1]);
	if (g->south.is_valid)
	{
		if (g->south.is_bad_extention)
			return (ft_error("SO : Wrong texture extention"));
		if (init_texture(&(g->south), g) == -1)
			return (ft_error("SO : Can't load texture."));
		return (0);
	}
	return (ft_error("SO : Invalid texture or color"));
}

int		parse_west(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_str_arr(words) != 2 || g->west.id[0] || g->str_map != NULL)
		return (ft_error("WE : Something wrong"));
	g->west = create_texture(words[0], words[1]);
	if (g->west.is_valid)
	{
		if (g->west.is_bad_extention)
			return (ft_error("WE : Wrong texture extention"));
		if (init_texture(&(g->west), g) == -1)
			return (ft_error("WE : Can't load texture."));
		return (0);
	}
	return (ft_error("WE : Invalid texture or color"));
}

int		parse_east(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_str_arr(words) != 2 || g->east.id[0] || g->str_map != NULL)
		return (ft_error("EA : Something wrong"));
	g->east = create_texture(words[0], words[1]);
	if (g->east.is_valid)
	{
		if (g->east.is_bad_extention)
			return (ft_error("EA : Wrong texture extention"));
		if (init_texture(&(g->east), g) == -1)
			return (ft_error("EA : Can't load texture."));
		return (0);
	}
	return (ft_error("EA : Invalid texture or color"));
}
