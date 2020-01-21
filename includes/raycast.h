/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:42:53 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/21 22:20:16 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

typedef struct	s_raycast
{
	double		camera_x;
	t_fvector	ray_dir;
	t_vector	map;
	t_fvector	delta_dist;
	t_vector	step;
	t_fvector	side_dist;
	double		non_eucl_dist;
	int			wall_start;
	int			wall_end;
	uint8_t		side:1;
	uint8_t		remain_bits:7;
}				t_raycast;

#endif
