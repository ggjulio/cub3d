/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 17:14:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/27 16:38:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_application	create_application(int size_x, int size_y, char *title)
{
	t_application app;

	app.resolution.x = size_x;
	app.resolution.y = size_y;
	app.title = title;
	app.mlx_ptr = mlx_init();
	app.win_ptr = mlx_new_window(app.mlx_ptr, size_x, size_y, title);
	app.img_ptr = mlx_new_image(app.mlx_ptr, size_x, size_y);
	app.pixels = mlx_get_data_addr(app.img_ptr, &(app.bits_per_pixel),
						&(app.size_line), &(app.endian));
	return (app);
}

void			destroy_application(t_application to_destroy)
{
	mlx_destroy_image(to_destroy.mlx_ptr, to_destroy.img_ptr);
	mlx_destroy_window(to_destroy.mlx_ptr, to_destroy.win_ptr);
}

void			put_pixel(t_application *app, t_vector coord, t_color color)
{
	int *pixels;

	if (coord.x < 0 || coord.y < 0 || coord.x >= app->resolution.x - 1
		|| coord.y >= app->resolution.y - 1)
		return ;
	pixels = (int *)(app->pixels);
	pixels[coord.x + (app->resolution.x * coord.y)] = color.c;
}

void			render_application(t_application *app)
{
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img_ptr, 0, 0);
}
