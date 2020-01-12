/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:51:02 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/12 15:08:08 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color     color_create(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	t_color color;

	color.rgba.r = r;
	color.rgba.g = g;
	color.rgba.b = b;
	color.rgba.a = a;

	return (color);
}

t_color     *color_malloc(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	t_color *color_ptr;

	if (!(color_ptr = malloc(sizeof(t_color))))
		return (NULL);
	*color_ptr = color_create(r, g, b, a);
	return (color_ptr);
}

void        color_destroy(t_color to_destroy)
{
	(void)to_destroy;
}

void        color_free(t_color *to_free)
{
	color_destroy(*to_free);
	free(to_free);
}
