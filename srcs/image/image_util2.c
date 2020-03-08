/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:38:53 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/08 16:55:17 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_opacity_image(t_image p_img, uint8_t p_opacity)
{
	int		i;
	int		nb_pixel;
	t_color	tmp;

	nb_pixel = p_img.size.x * p_img.size.y;
	i = -1;
	while (++i < nb_pixel)
	{
		tmp.c = p_img.pixels[i];
		tmp.rgba.a = p_opacity;
		p_img.pixels[i] = tmp.c;
	}
}

void	set_opacity_image_if_color(
	t_image p_img, uint8_t p_opacity, t_color p_color)
{
	int		i;
	int		nb_pixel;
	t_color	tmp;

	nb_pixel = p_img.size.x * p_img.size.y;
	i = -1;
	while (++i < nb_pixel)
	{
		tmp.c = p_img.pixels[i];
		if (tmp.rgba.r == p_color.rgba.r
			&& tmp.rgba.g == p_color.rgba.g
			&& tmp.rgba.b == p_color.rgba.b)
		{
			tmp.rgba.a = p_opacity;
			p_img.pixels[i] = tmp.c;
		}
	}
}
