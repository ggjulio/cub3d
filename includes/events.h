/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:45:11 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/22 16:46:09 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "cub3d.h"

int		is_key_press(int key, t_game *g);
int		is_key_release(int key, t_game *g);
int		close_program(int key, t_game *g);

#endif
