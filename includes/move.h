/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:28:06 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/08 14:38:04 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

/*
** move_movement.c
*/
void	forward(double speed);
void	backward(double speed);
void	left(double lat_speed);
void	right(double lat_speed);

/*
** move_movement_camera.c
*/
void	rotate(double rot_speed);
void	look_up(void);
void	look_down(void);

/*
** move_mouse.c
*/
void	move(double speed, double lat_speed, double rot_speed);
void	mouse_movement(void);

#endif
