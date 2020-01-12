/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:05:14 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/12 14:22:10 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector    vector_create(int x, int y)
{
	t_vector vector;

	vector.x = x;
	vector.x = y;

	return (vector);
}

t_vector    *vector_malloc(int x, int y)
{
	t_vector *vector_ptr;

	if (!(vector_ptr = malloc(sizeof(t_vector))))
		return (NULL);
	*vector_ptr = vector_create(x, y);
	return (vector_ptr);
}

void        vector_destroy(t_vector to_destroy)
{
	(void)to_destroy;
}

void        vector_free(t_vector *to_free)
{
	vector_destroy(*to_free);
	free(to_free);
}
