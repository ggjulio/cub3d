/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:24:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/15 20:08:11 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bmp_header	create_bmp_header(
					uint16_t  type, uint32_t  size, uint32_t  offset)
{
	t_bmp_header result;

	ft_bzero(&result, sizeof(t_bmp_header));
	result.type = type;
	result.size = size;
	result.offset = offset;
	return (result);
}

t_bmp_header	init_bmp_header_reserved(
				t_bmp_header result, uint16_t  reserved1, uint16_t  reserved2)
{
	result.reserved1 = reserved1;
	result.reserved2 = reserved2;
	return (result);
}

void			save_image(char *file_name)
{
	
	t_bmp_header	header;
	uint8_t			type[2];
	int				fd;

	type[0] = 'B';
	type[1] = 'M';
	header = create_bmp_header((uint16_t)type, BMP_HEADER_SIZE + g_app.res.x * g_app.res.y, BMP_HEADER_SIZE);

	printf("%lu \n", 		   sizeof(t_bmp_header));
/*	header.dib.dib_header_size = sizeof(t_bmp_dib_header);
	header.dib.width_px = g_app.res.x;
	header.dib.height_px = g_app.res.y;
	header.dib.num_planes = 1;
	header.dib.bits_per_pixel = g_app.bits_per_pixel;
*/

	fd = open(file_name, O_RDWR | O_CREAT, 0666);

	write(fd, &header, sizeof(t_bmp_header));
	write(fd, g_app.pixels, g_app.size_line);
	close(fd);
}
