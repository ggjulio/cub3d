/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:50:30 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/23 16:28:40 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

/*
** events_key.c
*/
int		is_key_press(int key);
int		is_key_release(int key);
int		is_focus_out(void);
int		is_focus_in(void);
int		is_configure_notify(void);
int		is_mouse_moved(int key);
int		close_program(int key);

/*
** events_effects.c
*/
void    effects(int key);

#endif
