/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:52:22 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/12 15:16:34 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef	struct	s_rgba
{
	uint8 b;
	uint8 g;
	uint8 r;
	uint8 a;
}				t_rgba;

typedef union	u_color
{
	uint32_t	c;
	t_rgba		rgba;
}				t_color;

t_color			color_create(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
t_color			*color_malloc(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void			color_destroy(t_color to_destroy);
void			color_free(t_color *to_free);

#endif
