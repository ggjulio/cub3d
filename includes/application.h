/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:46:35 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/12 15:11:24 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLICATION_H
# define APPLICATION_H

typedef struct	s_resolution
{
	int x;
	int y;
}				t_resolution;

typedef struct	s_application
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;

	t_resolution	resolution;
}				t_application;

#endif
