/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:49:23 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 16:25:50 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOUND_H
# define SOUND_H

# include "cub3d.h"

typedef struct	s_sound
{
	char		*filename;
	FMOD_SOUND	*sound_ptr;
}				t_sound;

/*
typedef struct	s_fmod
{
	FMOD_SYSTEM *fmod_ptr;
	t_sound		shoot;
}				t_fmod;
*/
/*
** sound_management.h
*/
//t_fmod			create_fmod(void);
//void			destroy_fmod(t_fmod to_destroy);
t_sound			create_sound(void);
void			destroy_sound(t_sound to_destroy);

#endif
