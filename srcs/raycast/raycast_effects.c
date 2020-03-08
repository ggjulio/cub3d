/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:17:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/08 12:20:53 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color add_sunset(t_color pixel, int y, int y_start)
{
	t_color result;
	t_color sunset;
	int		p;

	(void)y_start;
	(void)y;
	p = g_app.res.y - y_start * 2;
//	p = (g_app.res.y / 2 - (y_start + 1)) - y_start;
	
	sunset = create_color(200, 50, 50, 0);
	sunset.rgba.a = p * 255 / (g_app.res.y);
	result = combine_color(pixel, sunset);
	result.rgba.a = pixel.rgba.a;
	return (result);
}

t_color add_fog(t_color pixel, int y_end)
{
	t_color result;
	t_color fog;
	int		p;

	p = g_app.res.y - y_end * 2;
	fog = g_game.fog_color;
	fog.rgba.a = p * 255 / (g_app.res.y);
	fog.rgba.a *= g_game.fog_ratio;
	result = combine_color(pixel, fog);
	result.rgba.a = pixel.rgba.a;
	return (result);
}
