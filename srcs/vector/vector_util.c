/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:45:11 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/23 20:02:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	add_vec_to_vec(t_vector p_v1, t_vector p_v2)
{
	t_vector result;

	result.x = p_v1 + p_v2;
	result.y = p_v1 + p_v2;
	return (result);
}
