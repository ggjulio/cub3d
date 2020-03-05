/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:45:11 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/26 12:12:47 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	add_vec_to_vec(t_vector p_v1, t_vector p_v2)
{
	t_vector result;

	result.x = p_v1.x + p_v2.x;
	result.y = p_v1.y + p_v2.y;
	return (result);
}

t_vector	sub_vec_to_vec(t_vector p_v1, t_vector p_v2)
{
	t_vector result;

	result.x = p_v1.x - p_v2.x;
	result.y = p_v1.y - p_v2.y;
	return (result);
}

t_vector	div_vec_by_scalar(t_vector p_vector, double n)
{
	t_vector result;

	result.x = (double)p_vector.x / n;
	result.y = (double)p_vector.y / n;
	return (result);
}

t_vector	mul_vec_by_scalar(t_vector p_vector, double n)
{
	t_vector result;

	result.x = (double)p_vector.x * n;
	result.y = (double)p_vector.y * n;
	return (result);
}

t_vector	abs_vec(t_vector p_vector)
{
	t_vector result;

	result.x = ft_abs(p_vector.x);
	result.y = ft_abs(p_vector.y);
	return (result);
}
