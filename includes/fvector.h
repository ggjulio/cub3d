/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvector.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 22:32:03 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/20 22:32:41 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FVECTOR_H
# define FVECTOR_H

typedef struct			s_fvector
{
	double	x;
	double	y;
}						t_fvector;


t_fvector				create_fvector(double x, double y);
t_fvector				*malloc_fvector(double x, double y);
void					destroy_fvector(t_fvector to_destroy);
void					free_fvector(t_fvector *to_free);

#endif
