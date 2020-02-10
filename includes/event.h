/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:50:30 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/10 15:36:14 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

int		is_key_press(int key);
int		is_key_release(int key);
int		is_focus_out(int key);
int		is_mouse_moved(int key);
int		close_program(int key);

#endif
