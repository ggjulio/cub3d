/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:37:51 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 10:03:04 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMING_H
# define TIMING_H

# include "cub3d.h"

double	clock_to_milliseconds(clock_t p_ticks);
double	clock_to_seconds(clock_t p_ticks);
double	get_fps(clock_t p_ticks);
void	ticks_begin(void);
void	ticks_end(void);

#endif
