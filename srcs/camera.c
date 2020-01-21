/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:52:56 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/21 17:43:40 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_camera create_camera(t_fvector position, t_fvector direction, t_fvector plane)
{
	t_camera camera;
	
	camera.pos = position;
	camera.dir = direction;
	camera.plane = plane;
	return (camera);
}

void destroy_camera(t_camera to_destroy)
{
	(void)to_destroy;
}
