/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_util_calc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:15:14 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/12 12:52:49 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	calc_obj_y_draw(int obj_line_height)
{
	t_vector result;

	result.x =
-obj_line_height * (1.0 - g_game.cam.height) + g_app.res.y * g_game.cam.height;
	result.y =
obj_line_height * g_game.cam.height + g_app.res.y * g_game.cam.height;
	result.x = (result.x < 0 ? 0 : result.x);
	result.y = (result.y > g_app.res.y ? g_app.res.y : result.y);
	return (result);
}
