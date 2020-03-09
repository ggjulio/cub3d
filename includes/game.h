/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:39:57 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/09 15:13:22 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

typedef struct	s_game
{
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

	t_image			reticle;
	t_image			weapon;

	double			fog_ratio;
	t_color			fog_color;

	int				y_offset;

	clock_t			ticks_begin;
	clock_t			ticks_end;
	clock_t			ticks_delta;
	int				fps;

	uint16_t		key_w:1;
	uint16_t		key_a:1;
	uint16_t		key_s:1;
	uint16_t		key_d:1;
	uint16_t		key_left:1;
	uint16_t		key_right:1;
	uint16_t		key_down:1;
	uint16_t		key_up:1;
	uint16_t		key_space:1;
	uint16_t		is_run:1;

	uint16_t		is_mouse_move:1;
	uint16_t		mouse_move_enabled:1;

	uint16_t		is_fog_on_ceil:1;
	uint16_t		is_sunset:1;
	uint16_t		show_map:1;

	uint16_t		remaining:1;
}				t_game;

/*
** game.c
*/
t_game			create_game(void);
t_game			*malloc_game(void);
void			destroy_game(t_game to_destroy);
void			free_game(t_game *to_free);

/*
** game_util.c
*/
void			load_textures(void);
int				loop_game(void);
uint8_t			map_value(int x, int y);
int				ft_error(char *e);
int				exit_game(void);

/*
** game_draw_map.c
*/
void			draw_map(void);

#endif
