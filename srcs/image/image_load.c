/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:13:44 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/24 12:26:12 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image		create_image_from_xpm(char *p_filename)
{
	t_image	result;

	result.img_ptr = mlx_xpm_file_to_image(g_app.mlx_ptr, p_filename,
				&(result.size.x), &(result.size.y));

	if (result.img_ptr == NULL)
		result.pixels = NULL;		
	else
	{
		result.pixels = (int *)mlx_get_data_addr(result.img_ptr,
			&(result.bits_per_pixel), &(result.size_line), &(result.endian));
		set_opacity_image(result, 100);
	}
	return (result);
}

t_image		*malloc_image_from_xpm(char *p_filename)
{
	t_image *result;

	if ((result = malloc(sizeof(t_image))) == NULL)
		return (NULL);
	*result = create_image_from_xpm(p_filename);
	return (result);
}
