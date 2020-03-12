/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:48:44 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 11:48:56 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	keep_ratio(t_image p_img, t_vector p_size)
{
	t_vector	result;
	float		ratio_actual_size;

	ratio_actual_size = (float)p_img.size.y / (float)p_img.size.x;
	if (p_size.x > p_size.y)
	{
		result.x = p_size.x;
		result.y = p_size.x * ratio_actual_size;
	}
	else
	{
		ratio_actual_size = (float)p_img.size.x / (float)p_img.size.y;
		result.y = p_size.y;
		result.x = p_size.y * ratio_actual_size;
	}
	return (result);
}

void		put_image_in_image(t_image p_img_base, t_image p_img_to_add,
			t_vector p_coord, t_vector p_size)
{
	int		x;
	int		y;
	float	step_y;
	float	step_x;

	x = -1;
	y = -1;
	step_y = (float)p_img_to_add.size.y / (float)p_size.y;
	step_x = (float)p_img_to_add.size.x / (float)p_size.x;
	while (++y < p_size.y)
	{
		while (++x < p_size.x)
		{
			put_pixel_to_image(
				p_img_base,
				add_vec_to_vec(p_coord, (t_vector){x, y}),
				get_pixel_from_image(p_img_to_add,
									x * step_x,
									y * step_y));
		}
		x = -1;
	}
}

void		put_image_in_image_center(t_image p_img_base,
				t_image p_img_to_add, t_vector p_size, t_vector offset)
{
	t_vector coord;

	coord.x = p_img_base.size.x / 2 - p_size.x / 2 + offset.x;
	coord.y = p_img_base.size.y / 2 - p_size.y / 2 + offset.y;
	put_image_in_image(p_img_base, p_img_to_add, coord, p_size);
}

void		put_image_in_image_center_bottom(t_image p_img_base,
				t_image p_img_to_add, t_vector p_size, t_vector offset)
{
	t_vector coord;

	coord.x = p_img_base.size.x / 2 - p_size.x / 2 + offset.x;
	coord.y = p_img_base.size.y - p_size.y + offset.y;
	put_image_in_image(p_img_base, p_img_to_add, coord, p_size);
}
