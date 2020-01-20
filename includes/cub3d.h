/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:21:40 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/20 22:44:17 by juligonz         ###   ########.fr       */
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

# include "vector.h"
# include "fvector.h"
# include "color.h"
# include "application.h"
# include "draw.h"



typedef struct	s_camera
{
	t_fvector pos;
	t_fvector dir;
	t_fvector plane;
}				t_camera;

typedef struct	s_game
{
	t_application	*app;
	t_camera		cam;
	uint8_t			*map;
}				t_game;


#endif
