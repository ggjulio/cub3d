/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 17:14:55 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/23 19:33:30 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			put_pixel(t_vector coord, t_color color)
{
	put_pixel_to_image(g_app.img, coord, color);
}

void			render_application(void)
{
	render_image(g_app.img);
}

void			clear_application(t_color color)
{
	clear_image(g_app.img, color);
}
