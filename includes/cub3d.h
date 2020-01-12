/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:21:40 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/12 20:22:09 by juligonz         ###   ########.fr       */
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
# include "color.h"
# include "application.h"

# define ERROR		-1

# define ERR_MAP		-2
# define ERR_NO_R	-3
# define ERR_NO_NO	-4
# define ERR_NO_SO	-5
# define ERR_NO_WE	-6
# define ERR_NO_EA	-7
# define ERR_NO_S	-8
# define ERR_NO_F	-9
# define ERR_NO_C	-10

#endif
