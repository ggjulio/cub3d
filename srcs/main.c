/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:14:37 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/12 22:15:18 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_rectangle(t_application *app, t_vector coord, t_vector size, t_color color)
{
	int x;
	int y;

	y = coord.y - 1;
	while (++y < coord.y + size.y)
	{
		x = coord.x - 1;
		while (++x < coord.x + size.x) 
			put_pixel(app, create_vector(x, y), color);
	}
}

int shit()
{

}

int	main(void)
{
	t_application app;

	app = create_application(1000, 1000, "Shit");

	draw_rectangle(&app, create_vector(0, 0), create_vector(100, 100), create_color(255,0,0,0));

	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img_ptr, 0, 0);
	mlx_string_put(app.mlx_ptr, app.win_ptr, 0, 0, create_color(255, 255, 255, 0).c, "Shit");


	mlx_loop_hook(app.mlx_ptr, shit, void *param);

	mlx_loop(app.mlx_ptr);
	return (0);
}
