/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:21:40 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/01 15:22:08 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"

# include "vectors.h"
# include "fvectors.h"
# include "x11.h"
# include "color.h"
# include "application.h"
# include "game.h"
# include "raycast.h"
# include "game.h"
# include "draw.h"

/*
** parser2.c
*/

int		parse_resolution(char **words, char *line, t_game *g);
int		parse_north(char **words, char *line, t_game *g);
int		parse_south(char **words, char *line, t_game *g);
int		parse_west(char **words, char *line, t_game *g);
int		parse_east(char **words, char *line, t_game *g);

/*
** parser.c
*/

int		parse_floor(char **words, char *line, t_game *g);
int		parse_ceil(char **words, char *line, t_game *g);
int		parse_sprite(char **words, char *line, t_game *g);
int		parsing(char *line, t_game *g);
int		load_cub(char *file, t_game *g);

/*
** utility.c
*/

int		count_str_arr(char **arr);
void	free_split(char **arr);
size_t	ft_strlen_charset(const char *s, const char *charset);

/*
** events.c
*/

int		is_key_press(int key, t_game *g);
int		is_key_release(int key, t_game *g);
int		is_focus_out(int key, t_game *g);
int		is_mouse_moved(int key, t_game *g);
int		close_program(int key, t_game *g);

/*
** raycasting.c
*/

void	raycasting(t_game *g);
uint8_t	map_value(t_game *g, int x, int y);

/*
** move.c
*/

void	move(t_game *g, double speed, double lat_speed, double rot_speed);

/*
** parse_map.c
*/

int		valid_map(t_game *g);
int		parse_str_map(char **words, char *line, t_game *g);

/*
** parse_map2.c
*/

int		str_map_to_map(t_game *g);

/*
** main.c
*/

int		ft_error(char *e);

#endif
