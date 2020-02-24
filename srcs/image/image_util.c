/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:38:53 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/24 17:36:39 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_to_image(t_image img, t_vector coord, t_color color)
{
	t_color actual;

	if (coord.x < 0 || coord.y < 0 || coord.x >= img.size.x
		|| coord.y >= img.size.y)
		return ;
	actual.c = img.pixels[coord.x + (coord.y * img.size.x)];
	img.pixels[coord.x + (coord.y * img.size.x)] =
		combine_color(actual, color).c;
}

void	set_opacity_image(t_image p_img, uint8_t p_opacity)
{
	int i;
	int nb_pixel;
	t_color tmp;

	nb_pixel = p_img.size.x * p_img.size.y;
	i = -1;
	while (++i < nb_pixel)
	{
		tmp.c = p_img.pixels[i];
		tmp.rgba.a = p_opacity;
		p_img.pixels[i] = tmp.c;
	}
}

t_color	get_pixel_from_image(t_image img, int x, int y)
{
	return ((t_color){.c = img.pixels[x + (y * img.size.x)]});
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
