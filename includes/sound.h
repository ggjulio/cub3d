/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:49:23 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 16:36:08 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOUND_H
# define SOUND_H

# include "cub3d.h"

typedef struct	s_sound
{
	char		*filename;
	FMOD_SOUND	*ptr;
}				t_sound;

/*
** sound_management.h
*/
t_sound			create_sound(char *p_filename);
void			destroy_sound(t_sound to_destroy);
void			load_sounds(void);
void			play_sound(t_sound p_sound);

#endif
