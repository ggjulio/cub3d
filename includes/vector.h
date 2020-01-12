/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:01:42 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/12 15:15:42 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct			s_coordinate
{
	int	x;
	int	y;
}						t_coordinate;

typedef	t_coordinate	t_vector;

t_vector				vector_create(int x, int y);
t_vector				*vector_malloc(int x, int y);
void					vector_destroy(t_vector to_destroy);
void					vector_free(t_vector *to_free);

#endif
