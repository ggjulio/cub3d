/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:48:34 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/06 13:48:36 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"

/*
** parser.c
*/

int		parse_floor(char **words, char *line);
int		parse_ceil(char **words, char *line);
int		parse_sprite(char **words, char *line);
int		parsing(char *line);
int		load_cub(char *file);

/*
** parser2.c
*/

int		parse_resolution(char **words, char *line);
int		parse_north(char **words, char *line);
int		parse_south(char **words, char *line);
int		parse_west(char **words, char *line);
int		parse_east(char **words, char *line);

/*
** parse_map.c
*/

int		valid_map(void);

/*
** parse_map2.c
*/

int		parse_str_map(char *line);
int		str_map_to_map(void);

#endif
