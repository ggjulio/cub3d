/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:46:35 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/22 17:16:24 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLICATION_H
# define APPLICATION_H

typedef struct	s_application
{
	char			*title;
	t_vector		screen_res;
	t_vector		win_res;
	t_vector		res;

	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;

	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				*pixels;
}				t_application;

t_application	create_application(void);
t_application	init_application(
					t_application actual, int size_x, int size_y, char *title);
t_application	*malloc_application(int size_x, int size_y, char *title);
void			destroy_application(t_application to_destroy);
void			free_application(t_application *to_free);

void			put_pixel(t_vector coord, t_color color);
void			render_application(void);
void			clear_application(t_color color);

void			rainbow_bar(void);

#endif
