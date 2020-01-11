/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:14:37 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/11 15:20:17 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

typedef s_application
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	
}		t_application;

int	main(void)
{
	t_application app;

	app.mlx_ptr = mlx_init();
	app.win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Name windows");
	
	mlx_string_put(app.mlx_ptr, app.win_ptr, 300, 300, 14474240, "HELLO WORLD");
	
	mlx_loop(app.mlx_ptr);
}

