/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:15:54 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/10 15:37:15 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "cub3d.h"

typedef struct	s_camera
{
	t_fvector	pos;
	t_fvector	dir;
	t_fvector	plane;
}				t_camera;

t_camera		create_camera(t_fvector position,\
						t_fvector direction, t_fvector plane);
t_camera		*malloc_camera(t_fvector position,\
						t_fvector direction, t_fvector plane);
void			destroy_camera(t_camera to_destroy);
void			free_camera(t_camera *to_free);

#endif
