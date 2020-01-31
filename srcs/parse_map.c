/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:09:50 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/31 16:18:34 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		valid_map_first_line(t_game *g)
{
	int i;
	int len;
	int nb_one;

	i = 0;
	len = 0;
	nb_one = 0;
	while (len < g->map_len_x)
	{
		if (g->str_map[i] != ' ')
			len++;
		if (g->str_map[i] == '1')
			nb_one++;
		i++;
	}
	if (nb_one == g->map_len_x)
		return (1);
	return (ft_error("Map : Invalid first line."));
}

int		valid_map_last_line(t_game *g)
{
	int i;
	int len;
	int nb_one;

	if (g->str_map == NULL)
		return (ft_error("Map : map not defined ?"));
	i = ft_strlen(g->str_map) - 1;
	len = 0;
	nb_one = 0;
	while (len < g->map_len_x)
	{
		if (g->str_map[i] != ' ')
			len++;
		if (g->str_map[i] == '1')
			nb_one++;
		i--;
	}
	if (nb_one == g->map_len_x)
		return (1);
	return (ft_error("Map : Invalid last line."));
}

int		valid_map(t_game *g)
{
	int i;
	int is_pos;

	if (valid_map_first_line(g) == -1 || valid_map_last_line(g) == -1)
		return (-1);
	if (!g->app.res.x || !g->north.id[0] || !g->south.id[0] || !g->east.id[0] ||
		!g->west.id[0] || !g->ceil.id[0] || !g->floor.id[0] || !g->sprite.id[0])
		return (ft_error("File : Missing ids"));
	i = -1;
	is_pos = 0;
	while (g->str_map[++i])
		if (ft_in_charset(g->str_map[i], "NSWE"))
		{
			is_pos = 1;
			break ;
		}
	if (!is_pos)
		return (ft_error("Map : No start position defined"));
	return (0);
}

int		valid_line(char *line, t_game *g)
{
	static uint8_t	is_pos;
	int				i;
	char			*tmp;

	(void)g;
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

int		parse_str_map(char **words, char *line, t_game *g)
{
	char	*tmp;

	(void)words;
	if (g->str_map == NULL)
	{
		if ((g->str_map = malloc(1)) == NULL)
			return (ft_error("malloc : Failed to allocate memory"));
		g->str_map[0] = '\0';
		g->map_len_x = ft_strlen_charset(line, "012NSWE");
	}
	else if (ft_strlen_charset(line, "012NSWE") != g->map_len_x)
		return (ft_error("Map : Different len"));
	if (g->map_len_x < 3)
		return (ft_error("Map : Minimal size is 3 by 3"));
	if (valid_line(line, g) == -1)
		return (-1);
	tmp = g->str_map;
	g->str_map = ft_strjoin(tmp, line);
	free(tmp);
	g->map_len_y++;
	return (0);
}
