/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:50:30 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/23 17:06:29 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

/*
** events.c
*/
int		is_focus_out(void);
int		is_focus_in(void);
int		is_configure_notify(void);
int		is_mouse_moved(int key);
int		close_program(int key);

/*
** events_key.c
*/
int		is_key_press(int key);
int		is_key_release(int key);

/*
** events_effects.c
*/
void	key_effects(int key);

#endif
