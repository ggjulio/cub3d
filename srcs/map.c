/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:00:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/30 15:42:08 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_position(t_vector pos, char c, t_game *g)
{
	(void)pos;
	g->cam.pos.x = 2 + 0.5; 
	g->cam.pos.y = 2 + 0.5;
    g->cam.plane.x = 0.0; 
    g->cam.plane.y = 0.66; 
	if (c == 'N')
	{
		g->cam.dir.x = -1.0; 
		g->cam.dir.y = 0.0;
	}
	else if (c == 'S')
	{
		g->cam.dir.x = 1.0; 
		g->cam.dir.y = 0.0;
	}
	else if (c == 'E')
	{
		g->cam.dir.x = 1.0; 
		g->cam.dir.y = 0.0;

	}
	else if (c == 'W')
	{
		g->cam.dir.x = 0.0; 
		g->cam.dir.y = -1.0;
	}
}

int		str_map_to_map(t_game *g)
{
	int i;
	int j;

	if ((g->map = malloc(g->map_len_x * g->map_len_y)) == NULL)
		return (-1);
	i = 0;
	j = 0;
	while (g->str_map[i])
	{
		while (g->str_map[i] == ' ')
			i++;
		if (in_charset(g->str_map[i], "NSWE"))
		{
			save_position((t_vector){0 , 0}, g->str_map[i], g);
			g->map[j++] = 0;
			i++;
		}
		else
			g->map[j++] = g->str_map[i++] - '0';
	}
	return (0);
}

int valid_map_first_line(t_game *g)
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
	return (nb_one == g->map_len_x);
}

int valid_map_last_line(t_game *g)
{
	int i;
	int len;
	int nb_one;

	if (g->str_map == NULL)
		return (0);
	i = ft_strlen(g->str_map) - 1;
	len = 0;
	nb_one = 0;
	while (len < g->map_len_x)
	{
		if (g->str_map[i] != ' ')
			len++;
		if (g->str_map[i] == '1')
			nb_one++;
		i--;;
	}
	return (nb_one == g->map_len_x);
}


int in_charset(char c, const char *charset)
{
	int i;
	
	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

size_t	ft_strlen_ignore(const char *s, const char *ignore_charset)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (!in_charset(s[i], ignore_charset))
			len++;
		i++;
	}
	return (len);
}

int		valid_line(char *line, t_game *g)
{
	static uint8_t	is_pos;
	int 			i;
	char			*tmp;

	(void)g;
	i = 0;
	tmp = ft_strrchr(line, '1');
	while (tmp[++i])
		if (tmp[i] != ' ')
			return (0);
	i = 0;
	while (line[++i])
	{
		if (in_charset(line[i], "NSEW"))
		{
			if (is_pos)
				return (0);
			is_pos = 1;
		}
		if (!in_charset(line[i], "012NSEW "))
			return (0);
	}
	return (1);
}

int		parse_str_map(char **words, char *line, t_game *g)
{
	char	*tmp;

	(void)words;
	if (g->str_map == NULL)
	{
		if ((g->str_map = malloc(1)) == NULL) // !!!!!!!!!!!!!
			return (-1); 
		g->str_map[0] = '\0';
		g->map_len_x = ft_strlen_ignore(line, " ");
	}
	else if (ft_strlen_ignore(line, " ") != g->map_len_x)
		return (-1);
	if (g->map_len_x < 3 || !valid_line(line, g))
		return (-1);
	tmp = g->str_map;
	g->str_map = ft_strjoin(tmp, line);
	free(tmp);
	g->map_len_y++;
	return (0);
}
