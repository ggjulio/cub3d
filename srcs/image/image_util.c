/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:38:53 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/23 19:49:51 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_to_image(t_image img, t_vector coord, t_color color)
{
	t_color actual;

	if (coord.x < 0 || coord.y < 0 || coord.x >= g_app.res.x
		|| coord.y >= g_app.res.y)
		return ;
	actual.c = img.pixels[coord.x + (g_app.res.x * coord.y)];
	img.pixels[coord.x + (coord.y * g_app.res.x)] =
		combine_color(actual, color).c;
}

void	render_image(t_image p_img)
{
	mlx_put_image_to_window(g_app.mlx_ptr,
							g_app.win_ptr,
							p_img.img_ptr,
							0,
							0);
}

void	clear_image(t_image p_img, t_color color)
{
	int i;
	int nb_pixel;

	nb_pixel = p_img.size.x * p_img.size.y - 1;
	i = -1;
	while (++i < nb_pixel)
		p_img.pixels[i] = color.c;
}
