/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:59:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/30 19:51:41 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef int	(*t_handler)(char **words, char *line, t_game *g);

int		count_str_arr(char **arr)
{
	int len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

int		ft_isnumber(char *s)
{
	int i;

	i = 0;
	while (s[i])
		if (!ft_isdigit(s[i++]))
			return (0);
	return (1);
}

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
	return (0);
}

int		parse_north(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_str_arr(words) != 2 || g->north.id[0] || g->str_map != NULL)
		return (ft_error("NO : Something wrong"));
	g->north = create_texture(words[0], words[1]);
	if (g->north.is_valid)
		return (0);
	return (ft_error("NO : Invalid texture or color"));
}

int		parse_south(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_str_arr(words) != 2 || g->south.id[0] || g->str_map != NULL)
		return (ft_error("SO : Something wrong"));
	g->south = create_texture(words[0], words[1]);
	if (g->south.is_valid)
		return (0);
	return (ft_error("SO : Invalid texture or color"));
}

int		parse_west(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_str_arr(words) != 2 || g->west.id[0] || g->str_map != NULL)
		return (ft_error("WE : Something wrong"));
	g->west = create_texture(words[0], words[1]);
	if (g->west.is_valid)
		return (0);
	return (ft_error("WE : Invalid texture or color"));
}

int		parse_east(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_str_arr(words) != 2 || g->east.id[0] || g->str_map != NULL)
		return (ft_error("EA : Something wrong"));
	g->east = create_texture(words[0], words[1]);
	if (g->east.is_valid)
		return (0);
	return (ft_error("EA : Invalid texture or color"));
}

int		parse_floor(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_str_arr(words) != 2 || g->floor.id[0] || g->str_map != NULL)
		return (ft_error("F : Something wrong"));
	g->floor = create_texture(words[0], words[1]);
	if (g->floor.is_valid)
		return (0);
	return (ft_error("F : Invalid texture or color"));
}

int		parse_ceil(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_str_arr(words) != 2 || g->ceil.id[0] || g->str_map != NULL)
		return (ft_error("C : Something wrong"));
	g->ceil = create_texture(words[0], words[1]);
	if (g->ceil.is_valid)
		return (0);
	return (ft_error("C : Invalid texture or color"));
}

int		parse_sprite(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_str_arr(words) != 2 || g->sprite.id[0] || g->str_map != NULL)
		return (ft_error("S : Something wrong"));
	g->sprite = create_texture(words[0], words[1]);
	if (g->sprite.is_valid)
		return (0);
	return (ft_error("S : Invalid texture or color"));
}

void	free_split(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr[i]);
	free(arr);
	arr = NULL;
}

int		parsing(char *line, t_game *g)
{
	const char		ids[10][3] = {"R", "NO", "SO", "WE", "EA",
								"F", "C", "S", "1", ""};
	const t_handler jmp_table[9] = {parse_resolution, parse_north,
									parse_south, parse_west,
									parse_east, parse_floor,
									parse_ceil, parse_sprite,
									parse_str_map};
	char			**words;
	int				i;
	int				ret;

	words = ft_split(line, ' ');
	if (words[0] == NULL)
		return (ft_error("File : spaces at empty line"));
	i = -1;
	while (ids[++i][0])
		if (ft_strncmp(words[0], ids[i], 2) == 0
			|| (words[0][0] == '1' && ft_strcmp(ids[i], "1") == 0))
		{
			ret = jmp_table[i](words, line, g);
			free_split(words);
			return (ret);
		}
	ft_printf("Undefined id : %s", words[0]);
	free_split(words);
	return (-1);
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
		if (in_charset(g->str_map[i], "NSWE"))
		{
			is_pos = 1;
			break ;
		}
	if (!is_pos)
		return (ft_error("Map : No start position defined"));
	return (0);
}

int		load_cub(char *file, t_game *g)
{
	char	*line;
	int		ret;
	int		fd;

	if (!ft_valid_extention(file, ".cub"))
		return (ft_error("File : invalid extention"));
	fd = open(file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (g->str_map != NULL && line[0] == '\0')
			return (ft_error("File : Must end with a single empty line"));
		if (line[0])
			ret = parsing(line, g);
		free(line);
		if (ret == -1)
			return (-1);
	}
	if (ret == -1)
		return (-1);
	ret = line[0] ? ft_error("Map : Missing nl at the last line") : 0;
	free(line);
	if (ret == -1 || valid_map(g) == -1 || str_map_to_map(g) == -1)
		return (-1);
	return (ret);
}
