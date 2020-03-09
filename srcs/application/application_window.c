/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 10:39:41 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/09 16:36:40 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rainbow_bar(void)
{
	static t_color	color = (t_color){.rgba={255, 0, 0, 255}};
	static uint8_t	speed = 15;
	char			title[20];

	if (color.rgba.r >= speed && color.rgba.b == 0)
	{
		color.rgba.r -= speed;
		color.rgba.g += speed;
	}
	if (color.rgba.g >= speed && color.rgba.r == 0)
	{
		color.rgba.g -= speed;
		color.rgba.b += speed;
	}
	if (color.rgba.b >= speed && color.rgba.g == 0)
	{
		color.rgba.b -= speed;
		color.rgba.r += speed;
	}
	ft_sprintf((char *)&title, "%3d, %3d, %3d\n",
			color.rgba.r,
			color.rgba.g,
			color.rgba.b);
	mlx_window_set_title(g_app.win_ptr, title);
	mlx_window_set_background(g_app.win_ptr, color.c);
}
