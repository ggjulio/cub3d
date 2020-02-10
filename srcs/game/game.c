/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/10 15:45:08 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game		create_game(void)
{
	t_game result;

	ft_bzero(&result, sizeof(t_game));
	return (result);
}

t_game		*malloc_game(void)
{
	t_game *result;

	if ((result = malloc(sizeof(t_game))) == NULL)
		return (NULL);
	*result = create_game();
	return (result);
}

void		destroy_game(t_game to_destroy)
{
	destroy_texture(to_destroy.north);
	destroy_texture(to_destroy.south);
	destroy_texture(to_destroy.east);
	destroy_texture(to_destroy.west);
	destroy_texture(to_destroy.ceil);
	destroy_texture(to_destroy.floor);
	destroy_texture(to_destroy.sprite);
	free(to_destroy.map);
	free(to_destroy.str_map);
}

void		free_game(t_game *to_free)
{
	destroy_game(*to_free);
	free(to_free);
}
