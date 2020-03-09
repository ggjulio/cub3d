/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:37:51 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/09 16:39:35 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMING_H
# define TIMING_H

# include "cub3d.h"

double	clockToMilliseconds(clock_t p_ticks);
double	clockToSeconds(clock_t p_ticks);
double	get_fps(clock_t p_ticks);

#endif 
