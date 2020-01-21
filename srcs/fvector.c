/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:05:14 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/21 17:45:17 by juligonz         ###   ########.fr       */
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

t_fvector	*malloc_fvector(double x, double y)
{
	t_fvector *fvector_ptr;

	if (!(fvector_ptr = malloc(sizeof(t_fvector))))
		return (NULL);
	*fvector_ptr = create_fvector(x, y);
	return (fvector_ptr);
}

void		destroy_fvector(t_fvector to_destroy)
{
	(void)to_destroy;
}

void		free_fvector(t_fvector *to_free)
{
	destroy_fvector(*to_free);
	free(to_free);
}
