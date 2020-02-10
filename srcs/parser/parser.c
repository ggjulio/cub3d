/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:59:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/06 16:39:38 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef int	(*t_handler)(char **words, char *line);

int		parse_floor(char **words, char *line)
{
	(void)line;
	if (count_str_arr(words) != 2 || g_game.floor.id[0] || g_game.str_map != NULL)
		return (ft_error("F : Something wrong"));
	g_game.floor = create_texture(words[0], words[1]);
	if (g_game.floor.is_valid)
	{
		if (g_game.floor.is_bad_extention)
			return (ft_error("F : Wrong texture extention"));
		if (init_texture(&(g_game.floor)) == -1)
			return (ft_error("F : Can't load texture."));
		return (0);
	}
	return (ft_error("F : Invalid texture or color"));
}

int		parse_ceil(char **words, char *line)
{
	(void)line;
	if (count_str_arr(words) != 2 || g_game.ceil.id[0] || g_game.str_map != NULL)
		return (ft_error("C : Something wrong"));
	g_game.ceil = create_texture(words[0], words[1]);
	if (g_game.ceil.is_valid)
	{
		if (g_game.ceil.is_bad_extention)
			return (ft_error("C : Wrong texture extention"));
		if (init_texture(&(g_game.ceil)) == -1)
			return (ft_error("C : Can't load texture."));
		return (0);
	}
	return (ft_error("C : Invalid texture or color"));
}

int		parse_sprite(char **words, char *line)
{
	(void)line;
	if (count_str_arr(words) != 2 || g_game.sprite.id[0] || g_game.str_map != NULL)
		return (ft_error("S : Something wrong"));
	g_game.sprite = create_texture(words[0], words[1]);
	if (g_game.sprite.is_valid)
	{
		if (g_game.sprite.is_bad_extention)
			return (ft_error("S : Wrong texture extention"));
		if (init_texture(&(g_game.sprite)) == -1)
			return (ft_error("S : Can't load texture."));
		return (0);
	}
	return (ft_error("S : Invalid texture or color"));
}

int		parsing(char *line)
{
	const char		ids[10][3] = {"R", "NO", "SO", "WE", "EA",
								"F", "C", "S", "1", ""};
	const t_handler jmp_table[9] = {parse_resolution, parse_north,
									parse_south, parse_west, parse_east,
									parse_floor, parse_ceil, parse_sprite,
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
			ret = jmp_table[i](words, line);
			free_split(words);
			return (ret);
		}
	ft_printf("Undefined id : %s", words[0]);
	free_split(words);
	return (-1);
}

int		load_cub(char *file)
{
	char	*line;
	int		ret;
	int		fd;

	if (!ft_valid_extention(file, ".cub"))
		return (ft_error("File : invalid extention"));
	fd = open(file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (g_game.str_map != NULL && line[0] == '\0')
			return (ft_error("File : Must end with a single empty line"));
		if (line[0])
			ret = parsing(line);
		free(line);
		if (ret == -1)
			return (-1);
	}
	if (ret == -1)
		return (-1);
	ret = line[0] ? ft_error("Map : Missing nl at the last line") : 0;
	free(line);
	if (ret == -1 || valid_map() == -1 || str_map_to_map() == -1)
		return (-1);
	return (ret);
}
