/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:48:44 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/23 20:08:05 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_to_image(t_image img_base, t_image img_to_add,
			t_vector coord, t_vector size)
{
	int x = -1;
	int y = -1;

	(void)size;
	while (++y < img_to_add.size.y)
	{
		while (++x < img_to_add.size.x)
		{
			put_pixel_to_image(img_base, coord.x + x , coord, (t_color.c)4);
		}
		x = -1;
	}
	return ;
}


