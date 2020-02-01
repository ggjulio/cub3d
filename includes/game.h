/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:39:57 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/01 16:28:57 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

typedef struct	s_camera
{
	t_fvector	pos;
	t_fvector	dir;
	t_fvector	plane;
}				t_camera;

t_camera		create_camera(t_fvector position,\
						t_fvector direction, t_fvector plane);

typedef struct	s_texture
{
	char		id[3];
	t_color		color;
	char		*filename;
	void		*img_ptr;
	char		*pixels;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_vector	size;
	uint8_t		is_texture:1;
	uint8_t		is_color:1;
	uint8_t		is_valid:1;
	uint8_t		remaining:6;
}				t_texture;

typedef struct	s_game
{
	t_application	app;
	t_camera		cam;
	uint8_t			map_len_x;
	uint8_t			map_len_y;
	char			*str_map;
	uint8_t			*map;

	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
	t_texture		ceil;
	t_texture		floor;
	t_texture		sprite;

	uint16_t		key_w:1;
	uint16_t		key_a:1;
	uint16_t		key_s:1;
	uint16_t		key_d:1;
	uint16_t		key_left:1;
	uint16_t		key_right:1;
	uint16_t		is_mouse_move:1;
	uint16_t		remaining:9;
}				t_game;

t_texture		create_texture(char id[3], char *value);
void			destroy_texture(t_texture tex, t_game *g);
void			init_tex(t_texture *tex, t_game *g);
void			load_textures(t_game *g);

void			destroy_game(t_game g);
int				exit_game(t_game *g);

#endif
