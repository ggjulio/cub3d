/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 17:14:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/23 16:09:03 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_application	create_application(void)
{
	t_application app;

	app.res.x = -1;
	app.res.y = -1;
	app.title = "";
	app.mlx_ptr = mlx_init();
	return (app);
}

t_application	init_application(
					t_application actual, int size_x, int size_y, char *title)
{
	t_application result;

	result.res.x = size_x;
	result.res.y = size_y;
	result.title = title;
	result.mlx_ptr = actual.mlx_ptr;
	result.win_ptr = mlx_new_window(result.mlx_ptr, size_x, size_y, title);
	result.img = create_image(result.res);
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
}

void			free_application(t_application *to_free)
{
	destroy_application(*to_free);
	free(to_free);
}
