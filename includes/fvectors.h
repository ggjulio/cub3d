/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvectors.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:12:12 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/14 16:48:11 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FVECTORS_H
# define FVECTORS_H

typedef struct	s_fvector
{
	double	x;
	double	y;
}				t_fvector;

t_fvector		create_fvector(double x, double y);
t_fvector		*malloc_fvector(double x, double y);
void			destroy_fvector(t_vector to_destroy);
void			free_fvector(t_vector *to_free);

t_fvector		perp_clock_fvec(t_fvector fvector);
t_fvector		perp_cntclock_fvec(t_fvector fvector);
t_fvector		multiply_fvec_by_dbl(t_fvector fvector, double n);
t_fvector		sub_fvec_by_fvec(t_fvector v1, t_fvector v2);

#endif
