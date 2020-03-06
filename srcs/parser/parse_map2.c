/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:09:50 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/06 16:40:03 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_position(t_vector pos, char c)
{
	double ratio;

	g_game.cam.pos.x = pos.x + 0.5;
	g_game.cam.pos.y = pos.y + 0.5;
	if (c == 'N')
		g_game.cam.dir = (t_fvector){0.0, -1.0};
	else if (c == 'S')
		g_game.cam.dir = (t_fvector){0.0, 1.0};
	else if (c == 'E')
		g_game.cam.dir = (t_fvector){1.0, 0.0};
	else if (c == 'W')
		g_game.cam.dir = (t_fvector){-1.0, 0.0};
	ratio = (double)g_app.res.x / (double)g_app.res.y;
	g_game.cam.plane = (t_fvector){
		(-0.5 * ratio) * g_game.cam.dir.y,
		(0.5 * ratio) * g_game.cam.dir.x,
	};
	g_game.cam.height = CAMERA_HEIGHT;
}

int		str_map_to_map(void)
{
	int x;
	int y;
	int k;

	if ((g_game.map = malloc(g_game.map_len_x * g_game.map_len_y)) == NULL)
		return (ft_error("Map : map malloc error "));
	y = -1;
	k = -1;
	ft_memset(g_game.map, '-', g_game.map_len_x * g_game.map_len_y);
	while (++y < g_game.map_len_y)
	{
		x = 0;
		while (g_game.str_map[++k] && g_game.str_map[k] != '\n')
		{
			if (x >= g_game.map_len_x)
				continue;
			if (ft_in_charset(g_game.str_map[k], "NSWE"))
			{
				save_position(
					(t_vector){x, y},
					g_game.str_map[k]);
				g_game.map[x + y * g_game.map_len_x] = 0;
			}
			else
				g_game.map[x + y * g_game.map_len_x] = g_game.str_map[k] - '0';
			x++;
		}
		while (x < g_game.map_len_x)
			g_game.map[x++ + y * g_game.map_len_x] = '-' - '0';
	}
	return (0);
}

size_t	ft_strlen_no_end_space(const char *s)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			len = ++i;
		else
			i++;
	}
	return (len);
}

int     parse_str_map(char *line)
{
    char    *tmp;
    size_t  line_len;

    line_len = ft_strlen_no_end_space(line);
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
