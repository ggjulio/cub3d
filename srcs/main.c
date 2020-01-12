/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:14:37 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/12 15:01:40 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_application app;
	
	app.mlx_ptr = mlx_init();
	app.win_ptr = mlx_new_window(app.mlx_ptr, 1000, 800, "Name windows");
	
//	mlx_string_put(app.mlx_ptr, app.win_ptr, 300, 300, 4231432, "HELLO WORLD");
	mlx_string_put(app.mlx_ptr, app.win_ptr, 300, 300, color_create(252, 3, 240, 0).c, "HELLO WORLD");
	mlx_string_put(app.mlx_ptr, app.win_ptr, 300, 300, color_create(252, 3, 0, 255).c, "HELLO WORLD");
	
	mlx_loop(app.mlx_ptr);
}

