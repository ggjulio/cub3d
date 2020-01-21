/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:46:35 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/21 22:22:13 by juligonz         ###   ########.fr       */
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
	char			*title;
	t_resolution	resolution;

	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;

	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*pixels;
}				t_application;

t_application	create_application(int size_x, int size_y, char *title);
t_application	*malloc_application(int size_x, int size_y, char *title);
void			destroy_application(t_application to_destroy);
void			free_application(t_application *to_free);
void			put_pixel(t_application *app, t_vector coord, t_color color);
int				run_application(t_application *application);
void			render_application(t_application *app);

#endif
