/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_effects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:26:23 by juligonz          #+#    #+#             */
/*   Updated: 2021/03/23 10:56:49 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	change_fog_color(void)
{
	static int		i;
	static t_color	arr[5] = {
			(t_color){.rgba.r=255, .rgba.g=255, .rgba.b=255},
			(t_color){.rgba.r=0, .rgba.g=186, .rgba.b=50},
			(t_color){.rgba.r=186, .rgba.g=0, .rgba.b=9},
			(t_color){.rgba.r=255, .rgba.g=234, .rgba.b=97},
			(t_color){.rgba.r=0, .rgba.g=0, .rgba.b=0}
		};

	if (i == 5)
		i = 0;
	g_game.fog_color = arr[i++];
}

void		key_effects(int key)
{
	if (key == XK_1)
		g_game.fog_ratio -= (g_game.fog_ratio >= 0.1 ? 0.1 : 0.0);
	else if (key == XK_2)
		g_game.fog_ratio += (g_game.fog_ratio <= 0.9 ? 0.1 : 0.0);
	else if (key == XK_3)
		change_fog_color();
	else if (key == XK_4)
		g_game.is_sunset = !g_game.is_sunset;
	else if (key == XK_5)
		g_game.is_fog_on_ceil = !g_game.is_fog_on_ceil;
}
