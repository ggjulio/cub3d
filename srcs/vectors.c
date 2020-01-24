/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:12:16 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/24 14:12:20 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	create_vector(int x, int y)
{
	t_vector vector;

	vector.x = x;
	vector.y = y;

	return (vector);
}

t_fvector	create_fvector(double x, double y)
{
	t_fvector fvector;

	fvector.x = x;
	fvector.y = y;

	return (fvector);
}
