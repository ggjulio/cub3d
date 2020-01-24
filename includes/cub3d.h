/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:21:40 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/24 14:20:14 by juligonz         ###   ########.fr       */
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
# include "events.h"
# include "draw.h"

int		load_cub(char *file, t_game *g);
int		exit_cub3d(t_game *g);

#endif
