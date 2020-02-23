/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvector_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:12:16 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/23 16:22:10 by juligonz         ###   ########.fr       */
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
