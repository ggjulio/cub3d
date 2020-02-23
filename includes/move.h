/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:28:06 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/23 16:08:09 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

void	rotate(double rot_speed);
void	forward(double speed);
void	backward(double speed);
void	left(double lat_speed);
void	right(double lat_speed);
void	look_up(void);
void	look_down(void);

void	move(double speed, double lat_speed, double rot_speed);
void	mouse_movement(void);

#endif
