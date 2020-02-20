/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvector_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:12:16 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/20 15:07:48 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_fvector	perp_clock_fvec(t_fvector fvector)
{
	t_fvector result;

	result = create_fvector(fvector.y, -fvector.x);
	return (result);
}

t_fvector	perp_cntclock_fvec(t_fvector fvector)
{
	t_fvector result;

	result = create_fvector(-fvector.y, fvector.x);
	return (result);
}

t_fvector	multiply_fvec_by_scalar(t_fvector fvector, double n)
{
	t_fvector result;

	result = create_fvector(fvector.x * n, fvector.y * n);
	return (result);
}

t_fvector	add_scalar_to_fvec(double n, t_fvector fvector)
{
	t_fvector result;

	result = create_fvector(fvector.x + n, fvector.y + n);
	return (result);
}

t_fvector	sub_fvec_by_fvec(t_fvector v1, t_fvector v2)
{
	t_fvector result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	return (result);
}

t_fvector	inverse_fvec(t_fvector p_fvect)
{
	t_fvector result;

	result.x = -p_fvect.x;
	result.y = -p_fvect.y;
	return (result);
}
