/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:37:12 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/09 16:37:25 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double clockToMilliseconds(clock_t p_ticks){
    return (p_ticks * 1000.0 / CLOCKS_PER_SEC);
}

double clockToSeconds(clock_t p_ticks){
    return ((double)p_ticks / (double)CLOCKS_PER_SEC);
}

double get_fps(clock_t p_ticks){
    return ((float)CLOCKS_PER_SEC / p_ticks);
}
