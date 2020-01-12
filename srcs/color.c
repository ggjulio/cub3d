/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:51:02 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/12 17:18:07 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color     create_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	t_color color;

	color.rgba.r = r;
	color.rgba.g = g;
	color.rgba.b = b;
	color.rgba.a = a;

	return (color);
}

t_color     *malloc_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	t_color *color_ptr;

	if (!(color_ptr = malloc(sizeof(t_color))))
		return (NULL);
	*color_ptr = create_color(r, g, b, a);
	return (color_ptr);
}

void        destroy_color(t_color to_destroy)
{
	(void)to_destroy;
}

void        free_color(t_color *to_free)
{
	destroy_color(*to_free);
	free(to_free);
}
