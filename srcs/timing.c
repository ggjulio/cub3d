/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:37:12 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/09 17:03:47 by juligonz         ###   ########.fr       */
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
