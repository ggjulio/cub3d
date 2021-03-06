/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:42:53 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 12:19:47 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

/*
** camera_x 	 : x-coordinate in camera space
** ray_dir  	 : direction of the ray.
** map			 : In which case of the map the camera is. (in decimal)
** delta_dist	 : Length of ray for x and y, from one x/y to another x/y case
** step			 : number of steps related to delta_dist
** side_dist	 : Distance between cam and first delta
** perp_wall_dist: Distance used on camera instead of euclidian distance
** y_draw.x	     : Begin index of wall in y axis
** y_draw.y		 : End index of wall in y axis
** side 		 : Position of wall hit. 0 for Nord/South or 1 for West/East
*/

enum	e_direction{None, North, South, East, West};

typedef struct	s_raycast
{
	double				camera_x;
	t_fvector			ray_dir;
	t_vector			map;
	t_fvector			delta_dist;
	t_vector			step;
	t_fvector			side_dist;
	double				perp_wall_dist;
	int					line_height;
	double				wall_x;
	t_vector			y_draw;
	enum e_direction	wall_side;

	t_list				*lst_sprite;

	uint8_t				side:1;
	uint8_t				remain_bits:7;
}				t_raycast;

/*
** raycast.c
*/
void			raycasting(void);

/*
** raycast_dda.c
*/
void			dda(t_raycast *r);

/*
** raycast_util.c
*/
t_texture		*get_texture_side(enum e_direction dir);
void			draw_ceil_floor(int x, int wall_start, int wall_end);
void			draw_wall_is_texture(t_raycast *r, int x, t_texture *texture);
void			draw_wall_is_color(
					int x, int y_start, int y_end, t_color pixel);

/*
** raycast_effects.c
*/
t_color			add_fog(t_color pixel, int y_end);
t_color			add_sunset(t_color pixel, int y_end);

/*
** raycast_effects.c
*/
t_vector		calc_obj_y_draw(int obj_line_height);

#endif
