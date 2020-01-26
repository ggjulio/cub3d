/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:52:22 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/26 15:36:05 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef	struct	s_rgba
{
	uint8_t b;
	uint8_t g;
	uint8_t r;
	uint8_t a;
}				t_rgba;

typedef union	u_color
{
	uint32_t	c;
	t_rgba		rgba;
}				t_color;

t_color			create_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
int				valid_color_fmt(char *format);
t_color			create_color_from_str(char *format);

#endif
