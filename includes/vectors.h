/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:01:42 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/24 14:16:30 by juligonz         ###   ########.fr       */
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

typedef struct			s_fvector
{
    double	x;
    double	y;
}                       t_fvector;

t_fvector				create_fvector(double x, double y);

#endif
