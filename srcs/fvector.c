/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvectors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:12:16 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/01 12:38:20 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_fvector	create_fvector(double x, double y)
{
	t_fvector fvector;

	fvector.x = x;
	fvector.y = y;
	return (fvector);
}

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

t_fvector	multip_fvec_by_dbl(t_fvector fvector, double n)
{
	t_fvector result;

	result = create_fvector(fvector.x * n, fvector.y * n);
	return (result);
}
