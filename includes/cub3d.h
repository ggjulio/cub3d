/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:21:40 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/27 18:19:07 by juligonz         ###   ########.fr       */
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
# include "x11.h"
# include "color.h"
# include "application.h"
# include "game.h"
# include "raycast.h"
# include "game.h"
# include "draw.h"

/*
** parser.c
*/

int	load_cub(char *file, t_game *g);
void free_split(char **arr);

/*
** events.c
*/

int	is_key_press(int key, t_game *g);
int	is_key_release(int key, t_game *g);
int	close_program(int key, t_game *g);

/*
** raycasting.c
*/

void raycasting(t_game *g, int worldMap[24][24]);

/*
** move.c
*/

void move(t_game *g, int worldMap[24][24]);

/*
** texture.c
*/

t_texture	create_texture(char id[3], char *value);
void		destroy_texture(t_texture tex, t_game *g);

#endif
