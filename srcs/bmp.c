/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:24:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/15 18:44:40 by juligonz         ###   ########.fr       */
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
	return(result)
}

void			save_image(void *img_ptr, char *file_name)
{
	
	t_bmp_header	header;
	char			type[3];

	type = "BM";
	header = create_bmp_header((int)type, );

}
