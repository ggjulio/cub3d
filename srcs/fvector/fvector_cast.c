/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvector_cast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:14:45 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/20 11:15:01 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector   fvec_to_vec(t_fvector fvector)
{
    t_vector result;

    result.x = (int)fvector.x;
    result.y = (int)fvector.y;
    return (result);
}
