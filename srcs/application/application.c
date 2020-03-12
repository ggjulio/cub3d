/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 17:14:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 17:20:26 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_application	create_application(void)
{
	t_application result;

	ft_bzero(&result, sizeof(t_application));
	result.res.x = -1;
	result.res.y = -1;
	result.title = "";
	result.mlx_ptr = mlx_init();
	return (result);
}

t_application	init_application(
					t_application actual, int size_x, int size_y, char *title)
{
	t_application result;

	result.res.x = size_x;
	result.res.y = size_y;
	result.win_res = result.res;
	result.title = title;
	result.mlx_ptr = actual.mlx_ptr;
	result.win_ptr = mlx_new_window(result.mlx_ptr, size_x, size_y, title);
	result.img = create_image(result.res);
	FMOD_System_Create(&result.fmod_ptr);
	FMOD_System_Init(result.fmod_ptr, FMOD_NB_CHANNELS, FMOD_INIT_NORMAL, NULL);
	return (result);
}

t_application	*malloc_application(int size_x, int size_y, char *title)
{
	t_application *app;

	if ((app = malloc(sizeof(t_application))) == NULL)
		return (NULL);
	*app = create_application();
	*app = init_application(*app, size_x, size_y, title);
	return (app);
}

void			destroy_application(t_application to_destroy)
{
	destroy_image(to_destroy.img);
	if (to_destroy.win_ptr != NULL)
		mlx_destroy_window(to_destroy.mlx_ptr, to_destroy.win_ptr);
	FMOD_System_Close(to_destroy.fmod_ptr);
	FMOD_System_Release(to_destroy.fmod_ptr);
}

void			free_application(t_application *to_free)
{
	destroy_application(*to_free);
	free(to_free);
}
