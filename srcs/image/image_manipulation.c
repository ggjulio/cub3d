/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:48:44 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/24 17:53:05 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_image_in_image(t_image img_base, t_image img_to_add,
			t_vector coord, t_vector p_size)
{
	int x = -1;
	int y = -1;

	int i = 0;
	int j = 0;

	float step_y = (float)img_to_add.size.y / (float)p_size.y;
	float step_x = (float)img_to_add.size.x / (float)p_size.x;

	(void)step_x;
	(void)step_y;
	while (++y < p_size.y &&  x * step_x < img_to_add.size.y)
	{
		while (++x < p_size.x && x * step_x < img_to_add.size.x)
		{
			put_pixel_to_image(
				img_base,
				add_vec_to_vec(coord, (t_vector){x, y}),
				get_pixel_from_image(img_to_add,x * step_x, y * step_y)
				);
			i++;
		}
		x = -1;
		i = 0;
		j++;
	}
}
