/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:21:40 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/15 19:22:29 by juligonz         ###   ########.fr       */
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
# include "texture.h"
# include "bmp.h"
# include "sprite.h"
# include "raycast.h"
# include "camera.h"
# include "game.h"
# include "draw.h"
# include "move.h"
# include "event.h"
# include "parse.h"
# include "utility.h"

# define FOV 0.58

# define ROT_SPEED 0.1

# define SPEED 0.11
# define LAT_SPEED 0.05

# define RUN_SPEED 0.4
# define RUN_LAT_SPEED 0.2

extern t_game			g_game;
extern t_application	g_app;

#endif
