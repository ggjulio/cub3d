/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:39:57 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/10 15:35:44 by juligonz         ###   ########.fr       */
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

	uint16_t		key_w:1;
	uint16_t		key_a:1;
	uint16_t		key_s:1;
	uint16_t		key_d:1;
	uint16_t		key_left:1;
	uint16_t		key_right:1;
	uint16_t		is_mouse_move:1;
	uint16_t		mouse_move_enabled:1;
	uint16_t		remaining:8;
}				t_game;

t_game			create_game(void);
t_game			*malloc_game(void);
void			destroy_game(void);
void			free_game(t_game *to_free);

void			load_textures(void);
int				exit_game(void);

#endif
