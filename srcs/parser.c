/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:59:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/23 21:44:19 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef int    (*t_handler)(char **words, t_game *g);

int parse_resolution(char **words, t_game *g)
{
	g->app.resolution.x = ft_atoi(words[1]);
	g->app.resolution.y = ft_atoi(words[2]);
	return(0);
}

int parse_north(char **words, t_game *g)
{

	(void)g;
	(void)words;
	return(0);
}

int parse_south(char **words, t_game *g)
{

	(void)g;
	(void)words;
	return(0);
}

int parse_west(char **words, t_game *g)
{

	(void)g;
	(void)words;
	return(0);
}

int parse_east(char **words, t_game *g)
{

	(void)g;
	(void)words;
	return(0);
}

int parse_floor(char **words, t_game *g)
{

	(void)g;
	(void)words;
	return(0);
}

int parse_ceil(char **words, t_game *g)
{

	(void)g;
	(void)words;
	return(0);
}

int parse_sprite(char **words, t_game *g)
{

	(void)g;
	(void)words;
	return(0);
}

int parse_map(char **words, t_game *g)
{
	(void)g;
	(void)words;
	return(0);
}

void free_2d_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int parse(char *line, t_game *g)
{
	const char symbol[10][3] = {"R", "NO", "SO", "WE", "EA", "F", "C", "S", "1", ""};
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

	words = ft_split(line, ' ');
	i = -1;
	while (symbol[++i][0])
		if (ft_strcmp(words[0], symbol[i]) == 0)
		{
			jmp_table[i](words, g);
			free_2d_array(words);
			return (0);
		}
	free_2d_array(words);
	free(words);
	free(words);
	return (-1);
}

int load_cub(char *file, t_game *g)
{
	char *line;
	int ret;
	int fd;

	fd = open(file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
//		printf("%s\n", line);
		parse(line, g);
		free(line);
	}

	free(line);
	return (0);
}



int	exit_cub3d(t_game *g)
{
	(void)g;
	//free tout
	exit(0);
	return(0);
}
