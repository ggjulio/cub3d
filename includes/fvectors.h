/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvectors.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:12:12 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/06 17:07:12 by juligonz         ###   ########.fr       */
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
t_fvector		perp_clock_fvec(t_fvector fvector);
t_fvector		perp_cntclock_fvec(t_fvector fvector);
t_fvector		multiply_fvec_by_dbl(t_fvector fvector, double n);

#endif
