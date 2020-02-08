/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:42:53 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/07 10:55:34 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

/*
** camera_x 	: x-coordinate in camera space
** ray_dir  	: direction of the ray.
** map			: In which case of the map the camera is. (in decimal)
** delta_dist	: Length of ray for x and y, from one x/y to another x/y case
** step			: number of steps related to delta_dist
** side_dist	: Distance between cam and first delta
** non_eucl_dist: Distance used on camera instead of euclidian distance
** wall_start	: Begin index of wall in y axis
** wall_end		: End index of wall in y axis
** side 		: Boolean, 0 if Nord/South or 1 if West/East
*/

typedef struct	s_raycast
{
	double		camera_x;
	t_fvector	ray_dir;
	t_vector	map;
	t_fvector	delta_dist;
	t_vector	step;
	t_fvector	side_dist;
	double		perp_wall_dist;
	int			line_height;
	double		wall_x;
	int			wall_start;
	int			wall_end;
	uint8_t		side:1;
	uint8_t		remain_bits:7;
}				t_raycast;

#endif
