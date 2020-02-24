/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:48:44 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/24 18:57:00 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_image_in_image(t_image p_img_base, t_image p_img_to_add,
			t_vector p_coord, t_vector p_size)
{
	int x = -1;
	int y = -1;

	int i = 0;
	int j = 0;

//	float step_y = (float)p_img_to_add.size.y / (float)p_size.y;
//	float step_x = (float)p_img_to_add.size.x / (float)p_size.x;
	float step_y = (float)g_app.win_res.y / (float)p_size.y;
	float step_x = (float)g_app.win_res.x / (float)p_size.x;

//	while (++y < p_size.y &&  x * step_x < p_img_to_add.size.y)
	while (++y < p_size.y &&  x * step_x < g_app.win_res.y)
	{
//		while (++x < p_size.x && x * step_x < p_img_to_add.size.x)
		while (++x < p_size.x && x * step_x < g_app.win_res.x)
		{
			put_pixel_to_image(
				p_img_base,
				add_vec_to_vec(p_coord, (t_vector){x, y}),
				get_pixel_from_image(p_img_to_add,x * step_x, y * step_y)
				);
			i++;
		}
		x = -1;
		i = 0;
		j++;
	}
}

void	put_image_in_image_center(t_image p_img_base, t_image p_img_to_add,
				t_vector p_size, t_vector offset)
{
    t_vector coord;

	coord.x = p_img_base.size.x / 2 - p_size.x / 2 + offset.x;
	coord.y = p_img_base.size.y / 2 - p_size.y / 2 + offset.y;
	put_image_in_image(p_img_base, p_img_to_add,  coord, p_size);
	ft_printf("%d, %d\n",coord.x, coord.y);
}
