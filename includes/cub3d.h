/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:21:40 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 22:27:53 by juligonz         ###   ########.fr       */
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
# include <pthread.h>

# include "mlx.h"
# include "fmod.h"
# include "libft.h"

# include "timing.h"
# include "sound.h"
# include "vectors.h"
# include "fvectors.h"
# include "x11.h"
# include "color.h"
# include "image.h"
# include "application.h"
# include "texture.h"
# include "bmp.h"
# include "raycast.h"
# include "sprite.h"
# include "camera.h"
# include "game.h"
# include "draw.h"
# include "move.h"
# include "event.h"
# include "parse.h"
# include "utility.h"

# define NB_THREAD 32
# define FMOD_NB_CHANNELS 4

# define WIN_MIN_WIDTH 100
# define WIN_MIN_HEIGHT 100

# define LIFE 100
# define LIFE_HIT 4

# define CAMERA_HEIGHT 0.5
# define CAMERA_HEIGHT_SQUAT 0.45

# define FOG_INTENSITY  0.9

# define ROT_SPEED 0.06

# define SPEED 0.12
# define LAT_SPEED 0.051
# define RUN_SPEED 0.4
# define RUN_LAT_SPEED 0.2

extern t_game			g_game;
extern t_application	g_app;

#endif
