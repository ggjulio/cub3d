/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:05:14 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/12 17:19:53 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	create_vector(int x, int y)
{
	t_vector vector;

	vector.x = x;
	vector.x = y;

	return (vector);
}

t_vector	*malloc_vector(int x, int y)
{
	t_vector *vector_ptr;

	if (!(vector_ptr = malloc(sizeof(t_vector))))
		return (NULL);
	*vector_ptr = create_vector(x, y);
	return (vector_ptr);
}

void		destroy_vector(t_vector to_destroy)
{
	(void)to_destroy;
}

void		free_vector(t_vector *to_free)
{
	destroy_vector(*to_free);
	free(to_free);
}
