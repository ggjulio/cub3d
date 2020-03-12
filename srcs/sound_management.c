/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:26:40 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 17:50:56 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sound	create_sound(char *p_filename)
{
	t_sound		result;
    FMOD_RESULT	ret;

	result.filename = ft_strnew(ft_strlen(p_filename));
	if (result.filename != NULL)
	{
		ft_strcpy(result.filename, p_filename);
		ret = FMOD_System_CreateSound(g_app.fmod_ptr, p_filename, FMOD_CREATESAMPLE, 0, &(result.ptr));
		if (ret != FMOD_OK)
		{
			ft_printf("File : can't load %s\n", p_filename);
			exit(0);
		}
	}
	return (result);
}

void	load_sounds(void)
{
	g_game.shoot = create_sound("sound/pan.wav");
	g_game.ambiance = create_sound("sound/horror_ambiance.wav");
}

void	play_sound(t_sound p_sound)
{
	FMOD_System_PlaySound(g_app.fmod_ptr, p_sound.ptr, NULL, 0, NULL);
}

void	pause_sound(t_sound p_sound)
{
	FMOD_System_PlaySound(g_app.fmod_ptr, p_sound.ptr, NULL, 1, NULL);
}

void	destroy_sound(t_sound to_destroy)
{
	free(to_destroy.filename);
	FMOD_Sound_Release(to_destroy.ptr);
}
