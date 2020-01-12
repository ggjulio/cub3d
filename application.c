/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 17:14:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/12 18:20:09 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_application   create_application(int size_x, int size_y, char *title)
{
	t_application app;

	app.resolution.x = size_x;
	app.resolution.y = size_y;
	app.title = title;
	app.mlx_ptr = mlx_init();
	app.win_ptr = mlx_new_window(app.mlx_ptr, size_x, size_y, title);
	app.pixel = mlx_get_data_addr(app.img_ptr, &(app.bits_per_pixel),
								  &(app.size_line), &(app.endian));
}

t_application   *malloc_application(int size_x, int size_y, char *title)
{
	(void)size_x;
}

void            destroy_application(t_application to_destroy)
{
	(void)to_destroy;
}

void            free_application(t_application *to_free)
{
	(void)to_free;
}
