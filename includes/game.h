/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:39:57 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/13 02:33:52 by juligonz         ###   ########.fr       */
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

	double			life;
	int				nb_kills;

	t_image			reticle;
	t_image			weapon[5];
	t_image			corona;
	t_image			health_bar;
	t_image			number[10];

	t_sound			shoot;
	t_sound			ambiance;
	t_sound			snapshot;
	t_sound			monster_killed;
	t_sound			game_over;

	double			fog_ratio;
	t_color			fog_color;

	int				y_offset;

	clock_t			ticks_begin;
	clock_t			ticks_end;
	clock_t			ticks_delta;
	float			fps;

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

	uint16_t		is_shoot:1;
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
int				ft_error(char *e);
int				exit_game(void);

/*
** game_map.c
*/
void			draw_map(void);
uint8_t			map_value(int x, int y);
void			set_map_value(int x, int y, uint8_t p_value);

/*
** game_hud.c
*/
void			draw_hud(void);

/*
** game_life.c
*/
void			check_life(void);
void			draw_life(void);

#endif
