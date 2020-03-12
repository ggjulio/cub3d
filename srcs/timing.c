/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:37:12 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 10:02:20 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	clock_to_milliseconds(clock_t p_ticks)
{
	return (p_ticks * 1000.0 / CLOCKS_PER_SEC);
}

double	clock_to_seconds(clock_t p_ticks)
{
	return ((double)p_ticks / (double)CLOCKS_PER_SEC);
}

double	get_fps(clock_t p_ticks)
{
	return ((float)CLOCKS_PER_SEC / p_ticks);
}

void    ticks_begin(void)
{
    g_game.ticks_begin = clock();
    g_game.ticks_delta = 0;
    g_game.ticks_end = 0;
    g_game.fps = 0;
}

void    ticks_end(void)
{
    g_game.ticks_end = clock();
    g_game.ticks_delta = g_game.ticks_end - g_game.ticks_begin;
    g_game.fps = get_fps(g_game.ticks_delta);
}
