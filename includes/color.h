/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:52:22 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/12 17:15:48 by juligonz         ###   ########.fr       */
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
t_color			*malloc_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void			destroy_color(t_color to_destroy);
void			free_color(t_color *to_free);

#endif
