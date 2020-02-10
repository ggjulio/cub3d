/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:51:02 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/09 21:00:55 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color		combine_color(t_color actual, t_color to_add)
{
	t_color result;
	float	alpha;

	alpha = to_add.rgba.a / 255.0f;
	result = create_color(
		actual.rgba.r * (1.0f - alpha) + to_add.rgba.r * alpha,
		actual.rgba.g * (1.0f - alpha) + to_add.rgba.g * alpha,
		actual.rgba.b * (1.0f - alpha) + to_add.rgba.b * alpha,
		255);
	return (result);
}
