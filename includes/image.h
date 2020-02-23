/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:52:56 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/23 13:14:14 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct	s_image
{
	void		*img_ptr;
	t_vector	size;

	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			*pixels;
}				t_image;

t_image		create_image(t_vector size);
t_image		*malloc_image(t_vector size);
void		destroy_image(t_image to_destroy);
void		free_image(t_image *to_free);

#endif
