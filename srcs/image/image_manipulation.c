/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:48:44 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/07 15:17:00 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector keep_ratio(t_image p_img, t_vector p_size)
{
	t_vector	result;
	float		ratio_screen;
	float		ratio_img_screen;
	float		ratio_actual_size;
	float		ratio_new_size;

	
	ratio_screen = (float)g_app.win_res.x / (float)g_app.win_res.y;
	ratio_img_screen = (float)g_app.res.x / (float)g_app.res.y;
	ratio_new_size = (float)p_size.x / (float)p_size.y;
	ratio_actual_size = (float)p_img.size.x / (float)p_img.size.y;

//	ft_printf("win(%4d,%4d)=%4f|  ", g_app.win_res.x, g_app.win_res.y, ratio_screen);
//	ft_printf("img(%4d,%4d)=%4f|  ", g_app.res.x, g_app.res.y, ratio_img_screen);


	t_vector delta = abs_vec(sub_vec_to_vec(g_app.win_res, g_app.res));


//	delta = add_vec_to_vec(g_app.win_res, delta);

	float ratio_delta = (float)delta.x / (float)delta.y;
	ft_printf("delta(%4d,%4d)=%4f|  ", delta.x, delta.y, ratio_delta);



	result = fvec_to_vec(multiply_fvec_by_scalar(vec_to_fvec(p_size), ratio_delta));
	
	
	
	
	
	ft_printf("res(%4d,%4d)=%4f\n|  ", result.x, result.y, (float)result.x / (float)result.y);

	return (result);
}

void	put_image_in_image(t_image p_img_base, t_image p_img_to_add,
			t_vector p_coord, t_vector p_size)
{
	int x = -1;
	int y = -1;

	int i = 0;
	int j = 0;

	float step_y = (float)p_img_to_add.size.y / (float)p_size.y;
	float step_x = (float)p_img_to_add.size.x / (float)p_size.x;

	while (++y < p_size.y)
	{
		while (++x < p_size.x)
		{
			put_pixel_to_image(
				p_img_base,
				add_vec_to_vec(p_coord, (t_vector){x, y}),
				get_pixel_from_image(p_img_to_add, 
									x * step_x,
									y * step_y)
				);
			i++;
		}
		x = -1;
		i = 0;
		j++;
	}
}

void	put_image_in_image_center(t_image p_img_base, t_image p_img_to_add,
				t_vector p_size, t_vector offset)
{
    t_vector coord;

	p_size = keep_ratio(p_img_to_add, p_size);
	coord.x = p_img_base.size.x / 2 - p_size.x / 2 + offset.x;
	coord.y = p_img_base.size.y / 2 - p_size.y / 2 + offset.y;
	put_image_in_image(p_img_base, p_img_to_add,  coord, p_size);
}
