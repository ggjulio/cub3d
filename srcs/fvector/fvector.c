/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvector.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:12:16 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/10 16:47:41 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_fvector	create_fvector(double x, double y)
{
	t_fvector result;

	result.x = x;
	result.y = y;
	return (result);
}

t_fvector	*malloc_fvector(double x, double y)
{
	t_fvector *result;

	if ((result = malloc(sizeof(t_fvector))) == NULL)
		return (NULL);
	*result = create_fvector(x, y);
	return (result);
}

void		destroy_fvector(t_vector to_destroy)
{
	(void)to_destroy;
}

void		free_fvector(t_vector *to_free)
{
	destroy_fvector(*to_free);
	free(to_free);
}
