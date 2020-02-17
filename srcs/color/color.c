/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:51:02 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/17 13:12:51 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color		create_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	t_color result;

	result.rgba.r = r;
	result.rgba.g = g;
	result.rgba.b = b;
	result.rgba.a = a;
	return (result);
}

t_color		*malloc_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	t_color	*result;

	if ((result = malloc(sizeof(t_color))) == NULL)
		return (NULL);
	*result = create_color(r, g, b, a);
	return (result);
}

void		destroy_color(t_color to_destroy)
{
	(void)to_destroy;
}

void		free_color(t_color *to_free)
{
	destroy_color(*to_free);
	free(to_free);
}
