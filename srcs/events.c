/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:44:33 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/27 18:16:46 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_key_press(int key, t_game *g)
{
	if (key == W_KEY)
		g->key_w = 1;
	else if (key == A_KEY)
		g->key_a = 1;
	else if (key == S_KEY)
		g->key_s = 1;
	else if (key == D_KEY)
		g->key_d = 1;
	else if (key == LEFT_KEY)
		g->key_left = 1;
	else if (key == RIGHT_KEY)
		g->key_right = 1;
	return (0);
}

int	is_key_release(int key, t_game *g)
{
	if (key == W_KEY)
		g->key_w = 0;
	else if (key == A_KEY)
		g->key_a = 0;
	else if (key == S_KEY)
		g->key_s = 0;
	else if (key == D_KEY)
		g->key_d = 0;
	else if (key == LEFT_KEY)
		g->key_left = 0;
	else if (key == RIGHT_KEY)
		g->key_right = 0;
	return (0);
}

int	close_program(int key, t_game *g)
{
	(void)key;
	return (exit_game(g));
}
