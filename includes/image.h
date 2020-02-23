/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:52:56 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/23 19:31:00 by juligonz         ###   ########.fr       */
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

/*
** image.c
*/
t_image			create_image(t_vector size);
t_image			*malloc_image(t_vector size);
void			destroy_image(t_image to_destroy);
void			free_image(t_image *to_free);

/*
** image_load.c
*/
t_image			create_image_from_xpm(char *p_filename);
t_image			*malloc_image_from_xpm(char *p_filename);

/*
** image_util.c
*/
void			put_pixel_to_image(t_image img, t_vector coord, t_color color);
void			render_image(t_image p_img);
void			clear_image(t_image p_img, t_color color);

#endif
