/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:59:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/27 17:24:31 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef int	(*t_handler)(char **words, t_game *g);

int count_words(char **words)
{
	int len;

	len = 0;
	while (words[len])
		len++;
	return (len);
}
int parse_resolution(char **words, t_game *g)
{
	if (count_words(words) != 3 || ft_atoi(words[1]) < 100 || ft_atoi(words[2]) < 100)
		return (-1);
	g->app = create_application(ft_atoi(words[1]), ft_atoi(words[2]), "Coucou");
	return(0);
}

int parse_north(char **words, t_game *g)
{
	if (count_words(words) != 2)
		return (-1);
	g->north = create_texture(words[0], words[1]);
	if (g->north.is_valid)
		return(0);
	return (-1);
}

int parse_south(char **words, t_game *g)
{
	if (count_words(words) != 2)
		return (-1);
	g->south = create_texture(words[0], words[1]);
	if (g->south.is_valid)
		return(0);
	return (-1);
}

int parse_west(char **words, t_game *g)
{
	if (count_words(words) != 2)
		return (-1);
	g->west = create_texture(words[0], words[1]);
	if (g->west.is_valid)
		return(0);
	return (-1);
}

int parse_east(char **words, t_game *g)
{
	if (count_words(words) != 2)
		return (-1);
	g->east = create_texture(words[0], words[1]);
	if (g->east.is_valid)
		return(0);
	return (-1);
}

int parse_floor(char **words, t_game *g)
{
	if (count_words(words) != 2)
		return (-1);
	g->floor = create_texture(words[0], words[1]);
	if (g->floor.is_valid)
		return(0);
	return (-1);
}

int parse_ceil(char **words, t_game *g)
{
	if (count_words(words) != 2)
		return (-1);
	g->ceil = create_texture(words[0], words[1]);
	if (g->ceil.is_valid)
		return(0);
	return (-1);
}

int parse_sprite(char **words, t_game *g)
{
	if (count_words(words) != 2)
		return (-1);
	g->sprite = create_texture(words[0], words[1]);
	if (g->sprite.is_valid)
		return(0);
	return (-1);
}

int parse_map(char **words, t_game *g)
{
//	static char *map;
//	char 
	
	(void)words;
	(void)g;
	return(0);
}

void free_split(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr[i]);
	free(arr);
	arr = NULL;
}

int parse(char *line, t_game *g)
{
	const char ids[10][3] = {"R", "NO", "SO", "WE", "EA", "F", "C", "S", "1", ""};
	const t_handler jmp_table[9] = {parse_resolution,
									parse_north,
									parse_south,
									parse_west,
									parse_east,
									parse_floor,
									parse_ceil,
									parse_sprite,
									parse_map};
	char **words;
	int i;
	int ret;

	words = ft_split(line, ' ');
	i = -1;
	while (ids[++i][0])
		if (ft_strcmp(words[0], ids[i]) == 0)
		{
			ret = jmp_table[i](words, g);
			free_split(words);
			return (ret);
		}
	free_split(words);
	return (-1);
}

/*
** Usage : 
**    valid_extention(filename, ".png");
*/
int valid_extention(char *filename, char *extention)
{
	char *file_ext;

	file_ext = ft_strrchr(filename, '.');
	if (ft_strcmp(file_ext, extention) == 0)
		return (1);
	return (0);
}

int load_cub(char *file, t_game *g)
{
	char *line;
	int ret;
	int fd;

	if (!valid_extention(file, ".cub"))
		return (-1);
	fd = open(file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!line[0])
			ret = parse(line, g);
		free(line);
		if (ret == -1)
			return (-1);
	}
//	ret = parse(line, g);
	free(line);
	if (ret == -1)
		return (-1);
	return (0);
}

int	exit_game(t_game *g)
{
	destroy_game(*g);
	exit(0);
	return(0);
}
