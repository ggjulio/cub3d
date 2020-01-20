/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:01:42 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/20 22:31:38 by juligonz         ###   ########.fr       */
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

t_vector				create_vector(int x, int y);
t_vector				*malloc_vector(int x, int y);
void					destroy_vector(t_vector to_destroy);
void					free_vector(t_vector *to_free);

#endif
