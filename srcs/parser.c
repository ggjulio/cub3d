/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:59:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/29 16:49:29 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef int	(*t_handler)(char **words, char *line, t_game *g);

int		count_words(char **words)
{
	int len;

	len = 0;
	while (words[len])
		len++;
	return (len);
}

int		parse_resolution(char **words, char *line, t_game *g)
{
	int x;
	int y;

	(void)line;
	x = ft_atoi(words[1]);
	y = ft_atoi(words[2]);
	if (count_words(words) != 3 || x < 100
		|| y < 100 || x > 2560 || y > 1440 || g->str_map != NULL)
		return (-1);
	if (g->app.res.x)
		return (-1);
	g->app.res.x = x;
	g->app.res.y = y;
	return (0);
}

int		parse_north(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_words(words) != 2 || g->north.id[0] || g->str_map != NULL)
		return (-1);
	g->north = create_texture(words[0], words[1]);
	if (g->north.is_valid)
		return (0);
	return (-1);
}

int		parse_south(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_words(words) != 2 || g->south.id[0] || g->str_map != NULL)
		return (-1);
	g->south = create_texture(words[0], words[1]);
	if (g->south.is_valid)
		return (0);
	return (-1);
}

int		parse_west(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_words(words) != 2 || g->west.id[0] || g->str_map != NULL)
		return (-1);
	g->west = create_texture(words[0], words[1]);
	if (g->west.is_valid)
		return (0);
	return (-1);
}

int		parse_east(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_words(words) != 2 || g->east.id[0] || g->str_map != NULL)
		return (-1);
	g->east = create_texture(words[0], words[1]);
	if (g->east.is_valid)
		return (0);
	return (-1);
}

int		parse_floor(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_words(words) != 2 || g->floor.id[0] || g->str_map != NULL)
		return (-1);
	g->floor = create_texture(words[0], words[1]);
	if (g->floor.is_valid)
		return (0);
	return (-1);
}

int		parse_ceil(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_words(words) != 2 || g->ceil.id[0] || g->str_map != NULL)
		return (-1);
	g->ceil = create_texture(words[0], words[1]);
	if (g->ceil.is_valid)
		return (0);
	return (-1);
}

int		parse_sprite(char **words, char *line, t_game *g)
{
	(void)line;
	if (count_words(words) != 2 || g->sprite.id[0] || g->str_map != NULL)
		return (-1);
	g->sprite = create_texture(words[0], words[1]);
	if (g->sprite.is_valid)
		return (0);
	return (-1);
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

int		parse(char *line, t_game *g)
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
		return (-1);
	i = -1;
	while (ids[++i][0])
		if (ft_strncmp(words[0], ids[i], 2) == 0
			|| (words[0][0] == '1' && ft_strcmp(ids[i], "1") == 0))
		{
			ret = jmp_table[i](words, line, g);
			free_split(words);
			return (ret);
		}
	free_split(words);
	return (-1);
}

int id_missing(t_game *g)
{
	int i;
	int is_pos;

	if (!g->app.res.x || !g->north.id[0] || !g->south.id[0] || !g->east.id[0]
		|| !g->west.id[0] || !g->ceil.id[0] || !g->floor.id[0] || !g->sprite.id[0])
		return (1);
	i = -1;
	is_pos = 0;
	while (g->str_map[++i] )
		if (in_charset(g->str_map[++i], "NSWE"))
		{
			is_pos = 1;
			break ;
		}
	return (!is_pos);
}

int		load_cub(char *file, t_game *g)
{
	char	*line;
	int		ret;
	int		fd;

	if (!ft_valid_extention(file, ".cub"))
		return (-1);
	fd = open(file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (g->str_map != NULL && line[0] == '\0')
			return (-1);
		if (line[0])
			ret = parse(line, g);
		free(line);
		if (ret == -1)
			return (-1);
	}
	if (ret == -1)
		return (-1);
	ret = line[0] ? -1 : 0;
	free(line);
	if (!valid_map_first_line(g) || !valid_map_last_line(g) || id_missing(g))
		return (-1);
//	parse_map(g);
	printf("|%s|\n", g->str_map);
	return (ret);
}
