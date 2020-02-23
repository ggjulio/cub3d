/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:53:45 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/23 13:14:05 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image		create_image(t_vector p_size)
{
	t_image result;

	result.size = p_size;
    result.img_ptr = mlx_new_image(g_app.mlx_ptr, p_size.x, p_size.y);
    result.pixels = (int *)mlx_get_data_addr(result.img_ptr,
			&(result.bits_per_pixel), &(result.size_line), &(result.endian));
	return (result);
}

t_image		*malloc_image(t_vector p_size)
{
	t_image *result;

    if ((result = malloc(sizeof(t_image))) == NULL)
		return (NULL);
	*result = create_image(p_size);
	return(result);
}

void		destroy_image(t_image to_destroy)
{
	if (to_destroy.img_ptr != NULL)
        mlx_destroy_image(g_app.mlx_ptr, to_destroy.img_ptr);
}

void		free_image(t_image *to_free)
{
	destroy_image(*to_free);
	free(to_free);
}
