/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:26:40 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 16:26:28 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
t_fmod	create_fmod(void)
{
	t_fmod result;

	FMOD_System_Create(&(result.fmod_ptr));
	FMOD_System_Init(result.fmod_ptr, 1, FMOD_INIT_NORMAL, NULL);
	return (result);
}

void	destroy_fmod(t_fmod to_destroy)
{
	FMOD_System_Close(to_destroy.fmod_ptr);
	FMOD_System_Release(to_destroy.fmod_ptr);
}
*/

t_sound	create_sound(char *p_filename)
{
	t_sound result;

	result.filename = ft_strnew(ft_strlen(p_filename));
	if (result.filename != NULL)
	{
		ft_strcpy(result.filename, p_filename);
		FMOD_System_CreateSound(g_aoo.fmod, p_filename,
			FMOD_CREATESAMPLE, 0, &(result.sound_ptr));
	}
	return (result);
}

void	play_sound(t_sound p_sound)
{
	FMOD_System_PlaySound(system, p_sound.fmod_ptr, NULL, 0, NULL);
}

void	destroy_sound(t_sound to_destroy)
{
	free(to_destroy.filename);
	FMOD_Sound_Release(tir);
}
