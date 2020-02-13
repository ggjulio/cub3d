/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:31:49 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/13 14:54:22 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "cub3d.h"

typedef struct	s_texture
{
	char		id[3];
	t_color		color;
	char		*filename;
	void		*img_ptr;
	int			*pixels;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_vector	size;
	uint8_t		is_texture:1;
	uint8_t		is_color:1;
	uint8_t		is_valid:1;
	uint8_t		is_bad_extention:1;
	uint8_t		remaining:4;
}				t_texture;

t_texture		create_texture(char id[3], char *value);
void			destroy_texture(t_texture tex);
int				init_texture(t_texture *tex);

#endif
