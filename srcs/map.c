/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:00:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/28 22:30:10 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
int		parse_map(t_game *g)
{
	g->str_map;
}
*/

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

int		valid_line_values(char *line, t_game *g)
{
	static uint8_t	is_pos;
	int 			i;

	i = 0;
	if (line[g->map_len_x - 1] != '1')
		return (0);
	while (line[++i])
	{
		if (in_set(line[i], "NSEW"))
		{
			if (is_pos)
				return (0);
			is_pos = 1;
		}
		if (!in_set(line[i], "012NSEW"))
			return (0);
	}
	return (1);
}

int		parse_str_map(char **words, char *line, t_game *g)
{
	char *tmp;

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
	if (g->map_len_x < 3 || !valid_line_values(line, g))
		return (-1);
	tmp = g->str_map;
	g->str_map = ft_strjoin(tmp, line);
	free(tmp);
	g->map_len_y++;
	return (0);
}