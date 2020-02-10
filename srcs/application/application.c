/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 17:14:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/10 14:39:47 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_application	create_application(int size_x, int size_y, char *title)
{
	t_application app;

	app.res.x = size_x;
	app.res.y = size_y;
	app.title = title;
	app.mlx_ptr = mlx_init();
	app.win_ptr = mlx_new_window(app.mlx_ptr, size_x, size_y, title);
	app.img_ptr = mlx_new_image(app.mlx_ptr, size_x, size_y);
	app.pixels = mlx_get_data_addr(app.img_ptr, &(app.bits_per_pixel),
						&(app.size_line), &(app.endian));
	return (app);
}

t_application	*malloc_application(int size_x, int size_y, char *title)
{
	t_application *app;

	if ((app = malloc(sizeof(t_application))) == NULL)
		return (NULL);
	*app = create_application(size_x, size_y, title);
	return (app);
}

void			destroy_application(t_application to_destroy)
{
	mlx_destroy_image(to_destroy.mlx_ptr, to_destroy.img_ptr);
	mlx_destroy_window(to_destroy.mlx_ptr, to_destroy.win_ptr);
}

void			free_application(t_application *to_free)
{
	destroy_application(*to_free);
	free(to_free);
}
