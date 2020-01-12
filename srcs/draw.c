/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:06:34 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/12 23:06:42 by juligonz         ###   ########.fr       */
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
