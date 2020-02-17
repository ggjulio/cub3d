/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 17:14:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/17 18:06:39 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			put_pixel(t_vector coord, t_color color)
{
	t_color actual;
	int		*pixels;

	if (coord.x < 0 || coord.y < 0 || coord.x >= g_app.res.x
		|| coord.y >= g_app.res.y)
		return ;
	pixels = (int *)(g_app.pixels);
	actual.c = pixels[coord.x + (g_app.res.x * coord.y)];
	pixels[coord.x + (g_app.res.x * coord.y)] = combine_color(actual, color).c;
}

void			render_application(void)
{
	mlx_put_image_to_window(g_app.mlx_ptr, g_app.win_ptr, g_app.img_ptr, 0, 0);
}

void			clear_application(t_color color)
{
	int i;
	int nb_pixel;
	int *pixels;

	nb_pixel = g_app.res.x * g_app.res.y - 1;
	pixels = (int *)(g_app.pixels);
	i = -1;
	while (++i < nb_pixel)
		pixels[i] = color.c;
}
