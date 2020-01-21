/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:52:18 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/21 17:39:15 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct	s_camera
{
	t_fvector pos;
	t_fvector dir;
	t_fvector plane;
}				t_camera;

t_camera	create_camera(t_fvector position, t_fvector direction, t_fvector plane);
void		destroy_camera(t_camera to_destroy);

#endif
