/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:12:16 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/01 11:04:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	create_vector(int x, int y)
{
	t_vector result;

	result.x = x;
	result.y = y;
	return (result);
}

t_vector	*malloc_vector(int x, int y)
{
	t_vector *result;

	if ((result = malloc(sizeof(t_vector))) == NULL)
		return (NULL);
	*result = create_vector(x, y);
	return (result);
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