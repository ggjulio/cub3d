/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/22 12:34:51 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_camera	create_camera(t_fvector position, t_fvector direction, \
						t_fvector plane)
{
	t_camera	camera;

	camera.pos = position;
	camera.dir = direction;
	camera.plane = plane;
	camera.height = 0.5;
	return (camera);
}

t_camera	*malloc_camera(t_fvector position, t_fvector direction, \
						t_fvector plane)
{
	t_camera *camera;

	if ((camera = malloc(sizeof(t_camera))) == NULL)
		return (NULL);
	*camera = create_camera(position, direction, plane);
	return (camera);
}

void		destroy_camera(t_camera to_destroy)
{
	(void)to_destroy;
}

void		free_camera(t_camera *to_free)
{
	destroy_camera(*to_free);
	free(to_free);
}
