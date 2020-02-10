/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:12:12 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/10 16:42:07 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

t_vector		create_vector(int x, int y);
t_vector		*malloc_vector(int x, int y);
void			destroy_vector(t_vector to_destroy);
void			free_vector(t_vector *to_free);

#endif
