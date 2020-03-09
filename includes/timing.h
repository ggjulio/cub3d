/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:37:51 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/09 17:02:38 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMING_H
# define TIMING_H

# include "cub3d.h"

double	clock_to_milliseconds(clock_t p_ticks);
double	clock_to_seconds(clock_t p_ticks);
double	get_fps(clock_t p_ticks);

#endif
