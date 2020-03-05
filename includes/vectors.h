/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:12:12 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/26 12:13:15 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include "cub3d.h"

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

/*
** vector.c
*/
t_vector		create_vector(int x, int y);
t_vector		*malloc_vector(int x, int y);
void			destroy_vector(t_vector to_destroy);
void			free_vector(t_vector *to_free);

/*
** vector_util.c
*/
t_vector		add_vec_to_vec(t_vector p_v1, t_vector p_v2);
t_vector		sub_vec_to_vec(t_vector p_v1, t_vector p_v2);
t_vector		div_vec_by_scalar(t_vector p_vector, double n);
t_vector		mul_vec_by_scalar(t_vector p_vector, double n);
t_vector		abs_vec(t_vector p_vector);

#endif
